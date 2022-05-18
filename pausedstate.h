#ifndef PAUSEDSTATE_H_INCLUDED
#define PAUSEDSTATE_H_INCLUDED

#include "button.h"
#include "inputmanager.h"
#include "state.h"

using namespace std;

class PausedState: public State {
    public:
        PausedState (InputManager *manager);
        ~PausedState ();
        void initialize () override;
        void exit () override;

        void run () override;
        void update () override;
        void draw () override;

    private:
        vector<Button*> mButtons;
        Texture *paused_frame;

        int index;                  // Shows the current button selected
};


#endif // PAUSEDSTATE_H_INCLUDED
