#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <utility>

Texture::Texture(SDL_Renderer* r, SDL_Surface* s)
{
    if(r && s) {
        rect.x = 0;
        rect.y = 0;
        rect.h = s->h;
        rect.w = s->w;

        pTexture = SDL_CreateTextureFromSurface(r, s);
    }
}

Texture::~Texture()
{
    if(pTexture) {
        SDL_DestroyTexture(pTexture);
        pTexture = nullptr;
    }
}

Texture::Texture(Texture&& rhs)
{
    rect = rhs.rect;
    pTexture = std::exchange(rhs.pTexture, nullptr);
}

Texture& Texture::operator=(Texture rhs)
{
    this->swap(rhs);
    return *this;
}

void Texture::swap(Texture& rhs) noexcept
{
    std::swap(rect, rhs.rect);
    std::swap(pTexture, rhs.pTexture);
}