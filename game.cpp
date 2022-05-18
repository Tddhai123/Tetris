#include "game.h"

#include <iostream>

#include "button.h"
#include "config.h"
#include "gamestate.h"
#include "menustate.h"
#include "optionsstate.h"
#include "pausedstate.h"
#include "state.h"

Game *Game::getInstance(){
    if (mInstance == nullptr) {
        mInstance = new Game;
    }
    return mInstance;
}

// The function called to initialize everything; Pushes the main menu state to the front
bool Game::initialize() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Could not initialize SDL! SDL_Error: " << SDL_GetError() << '\n';
        success = false;
    }
    else {
        mWindow = SDL_CreateWindow(config::window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        config::SCREEN_WIDTH, config::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (mWindow == nullptr) {
            cout << "Could not create window! SDL_Error: " << SDL_GetError() << '\n';
            success = false;
        }
        else {
            if (IMG_Init(IMG_INIT_PNG) == 0 || IMG_Init(IMG_INIT_JPG) == 0) {
                cout << "Could not initialize SDL_image! SDL_image error: " << IMG_GetError() << '\n';
                success = false;
            }
            if (TTF_Init() == -1) {
                cout << "Could not initialize SDL_ttf! SDL_ttf error: " << TTF_GetError() << '\n';
                success = false;
            }
        }
    }
    mRenderer = new Renderer;
    mRenderer->initialize(mWindow);

    // The logical resolution of the game never changes; We just alter the scaling
    SDL_RenderSetLogicalSize(mRenderer->mSDLRenderer, config::SCREEN_WIDTH, config::SCREEN_HEIGHT);
    SDL_SetWindowSize(mWindow, config::SCREEN_WIDTH*config::resolution_scaling, config::SCREEN_HEIGHT*config::resolution_scaling);
    SDL_SetWindowPosition(mWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    mManager = new InputManager;

    // Now load the main menu screen
    mMainMenuState = new MenuState(mManager);
    mMainMenuState->initialize();
    pushState(mMainMenuState);
    return success;
}

// Deletes all states loaded, deletes the window and closes all SDL services
void Game::exit () {
    for (auto i : mStates) {
        delete i;
    }

    delete mRenderer;

    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

// Main loop of the entire program. Gets the current state and simply runs it
void Game::run() {
    if (!mStates.empty()) {
        mStates.back()->run();
    }
}

// Deletes the current state
void Game::popState () {
    mStates.pop_back();
}

// Pushes a new state to the front
void Game::pushState (State *state) {
    mStates.push_back(state);
}

// Deletes the current state and replaces it with a different one
void Game::changeState (State *state) {
    popState();
    pushState(state);
}

// Pushes a new gamestate state to the front
void Game::pushNewGame () {
    Game::getInstance()->mPlayState = new GameState(Game::getInstance()->mManager);
    Game::getInstance()->mPlayState->initialize();
    Game::getInstance()->pushState(Game::getInstance()->mPlayState);
}

// Pushes the options to the front
void Game::pushOptions () {
    Game::getInstance()->mOptionsState = new OptionsState(Game::getInstance()->mManager);
    Game::getInstance()->mOptionsState->initialize();
    Game::getInstance()->pushState(Game::getInstance()->mOptionsState);
}

// Pushes the pause menu to the front
void Game::pushPaused () {
    Game::getInstance()->mPausedState = new PausedState (Game::getInstance()->mManager);
    Game::getInstance()->mPausedState->initialize();
    Game::getInstance()->pushState(Game::getInstance()->mPausedState);

}

// Goes back one state (by popping the state in the front)
void Game::goBack () {
    Game::getInstance()->popState();
}

// Pops the first 2 states
void Game::goDoubleBack () {
    Game::getInstance()->popState();
    Game::getInstance()->popState();
}

bool Game::isGameExiting () {
    if (mStates.empty()) {
        return true;
    }
    else {
        return mStates.back()->nextStateID == STATE_EXIT;
    }
}

Game *Game::mInstance = 0;

Game::Game () {}
