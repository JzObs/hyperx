#ifndef HYPERX_WINDOW_HPP
#define HYPERX_WINDOW_HPP

#include "Initializer.hpp"
#include <SDL2/SDL.h>
#include <memory>

class Window
{
private:
    SDL_Window* pWindow = nullptr;
    std::shared_ptr<Initializer> pInitializer;
public:
    Window(std::shared_ptr<Initializer> pinit, unsigned int width, unsigned int height);
    ~Window();

    SDL_Window* Raw()
    {
        return pWindow;
    }
};

#endif