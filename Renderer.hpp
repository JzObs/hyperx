#ifndef HYPERX_RENDERER_HPP
#define HYPERX_RENDERER_HPP

#include "Window.hpp"
#include "Object.hpp"
#include <SDL2/SDL.h>

class Renderer
{
private:
    SDL_Renderer* pRenderer = nullptr;
    std::shared_ptr<Window> pWindow;
public:
    Renderer(std::shared_ptr<Window> pw);
    ~Renderer();

    SDL_Renderer* Raw()
    {
        return pRenderer;
    }

    void Draw(const Star& s);
};

#endif