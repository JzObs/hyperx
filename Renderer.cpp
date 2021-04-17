#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(std::shared_ptr<Window> pw) : pWindow(pw)
{
    if(pWindow) {
        pRenderer = SDL_CreateRenderer(pWindow->Raw(), -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    } else {
        std::cout << "Couldn't create renderer" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(pRenderer);
}

void Renderer::Draw(const Star& s)
{
    unsigned int c = 32 * s.speed - 1;
	SDL_SetRenderDrawColor(pRenderer, c, c, c, 255);

    SDL_Rect r{(int)s.pos.x, (int)s.pos.y, (int)s.width, (int)s.height};
    SDL_RenderFillRect(pRenderer, &r);
}