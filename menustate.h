#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED

#include <vector>

#include <SDL2/SDL.h>

#include "button.h"
#include "inputmanager.h"
#include "renderer.h"
#include "state.h"

using namespace std;

// The main menu of the game; It is the state shown when the game starts
class MenuState: public State {
    public:
        MenuState (InputManager *manager);
        ~MenuState ();
        void initialize () override;
        void exit () override;

        void run () override;
        void update () override;
        void draw () override;

    private:
        vector<Button*> mButtons;
        Texture *title_text;
        int index;                          // Shows the current button selected
};

#endif // MENUSTATE_H_INCLUDED
