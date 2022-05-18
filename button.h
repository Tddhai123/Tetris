#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <string>

#include "texture.h"

using namespace std;

class Button {
    public:
        Button (string path, void (*callback) (), int posX = 0, int posY = 0);
        ~Button ();
        bool loadTexture (string path);
        void draw ();
        void (*callbackFunction) ();

        int getX ();
        int getY ();
        int getWidth ();
        int getHeight ();

    private:
        int position_x;
        int position_y;
        int width;
        int height;
        Texture *texture;
};

#endif // BUTTON_H_INCLUDED
