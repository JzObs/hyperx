#include "Initializer.hpp"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>

Initializer::Initializer()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
        std::exit(EXIT_FAILURE);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}

Initializer::~Initializer()
{
    SDL_Quit();
}