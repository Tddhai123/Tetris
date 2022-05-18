#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "renderer.h"

using namespace std;

class Renderer;

class Texture {
    public:
        Texture ();
        ~Texture ();
        void free ();

        bool loadFromImage (string path);
        bool loadFromText (string text, TTF_Font *font, SDL_Color text_color);
        void render (int x, int y, SDL_Rect *clip = nullptr);
        void renderCentered (int x, int y);
        void setAlphaMode (Uint8 alpha);

        int getWidth ();
        int getHeight ();

    private:
        SDL_Texture *mTexture;
        int width;
        int height;
};


#endif // TEXTURE_H_INCLUDED
