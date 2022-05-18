#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "texture.h"

using namespace std;

class Texture;

class Renderer {
    public:
        void initialize (SDL_Window *window);
        ~Renderer();

        void clearScreen();
        void renderTexture(Texture *texture, int x, int y);
        void updateScreen();
        SDL_Renderer *mSDLRenderer = nullptr;

        TTF_Font *mediumFont;
        TTF_Font *bigFont;
};

#endif // RENDERER_H_INCLUDED
