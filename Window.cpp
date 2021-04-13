#include "Window.hpp"

Window::Window(std::shared_ptr<Initializer> pinit, unsigned int width, unsigned int height) : pInitializer(pinit)
{
    if(pInitializer) {
        pWindow = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    }
}

Window::~Window()
{
    if(pWindow) {
        SDL_DestroyWindow(pWindow);
    }
}