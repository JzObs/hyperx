#ifndef HYPERX_RENDERER_HPP
#define HYPERX_RENDERER_HPP

#include "Window.hpp"
#include "Object.hpp"
#include "Texture.hpp"

struct SDL_Renderer;

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

    void Prepare();
    void Render();

    void Draw(const Star& s);
    void DrawEx(const Texture& t);
    void Draw(const Texture& t);
};

#endif