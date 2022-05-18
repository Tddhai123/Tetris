#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "inputmanager.h"
#include "renderer.h"
#include "state.h"

class State;
class GameState;
class MenuState;
class OptionsState;
class PausedState;

// Utilizes the "Singleton pattern" to ensure there can only be one game
class Game {
    public:
        friend class OptionsState;          // Options can change the window size
        static Game* getInstance();

        bool initialize ();
        void exit ();
        void run ();

        void popState ();
        void pushState (State *s);
        void changeState (State *s);

        static void pushOptions();
        static void pushNewGame();
        static void pushPaused();
        static void goBack();
        static void goDoubleBack();

        bool isGameExiting();

        Renderer *mRenderer;                // The renderer used for all things rendering

    private:
        static Game *mInstance;
        Game();
        SDL_Window *mWindow;
        InputManager *mManager;
        vector <State*> mStates;

        GameState *mPlayState;
        MenuState *mMainMenuState;
        OptionsState *mOptionsState;
        PausedState *mPausedState;
};

#endif // GAME_H_INCLUDED
