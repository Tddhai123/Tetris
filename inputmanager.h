#ifndef INPUTMANAGER_H_INCLUDED
#define INPUTMANAGER_H_INCLUDED

#include <SDL2/SDL.h>

enum class Action {
    stay_idle, back, move_up, move_down, move_left, move_right, select, drop, rotate, hold, pause
};

class InputManager {
    public:
        InputManager();
        void clearEventQueue();
        Action getAction();
        bool isGameExiting();
        bool pollAction();
        void setExit();
    private:
        bool quit_game;
        Action action;
};

#endif // INPUTMANAGER_H_INCLUDED
