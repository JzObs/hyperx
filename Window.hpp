#ifndef HYPERX_WINDOW_HPP
#define HYPERX_WINDOW_HPP

#include "Initializer.hpp"
#include <SDL2/SDL.h>
#include <memory>

class Window
{
public:
    Window(std::shared_ptr<Initializer> pinit, unsigned int width, unsigned int height);
    ~Window();

    SDL_Window* Raw()
    {
        return pWindow;
    }

    unsigned int GetWidth() const {return width;}
    unsigned int GetHeight() const {return height;}

private:
    SDL_Window* pWindow = nullptr;
    std::shared_ptr<Initializer> pInitializer;
    const unsigned int width, height;
};

#endif