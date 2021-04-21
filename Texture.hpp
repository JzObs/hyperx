#pragma once

#ifndef HYPERX_TEXTURE_HPP
#define HYPERX_TEXTURE_HPP

#include "Shape.hpp"

class SDL_Renderer;
class SDL_Surface;
class SDL_Texture;

class Texture
{
public:
    Texture() {}
    Texture(Rect r, SDL_Texture* t) : rect(r), pTexture(t) {}
    Texture(SDL_Renderer* r, SDL_Surface* s);
    ~Texture();
    Texture(const Texture&) = delete;
    Texture(Texture&& rhs);
    Texture& operator=(Texture rhs);

    SDL_Texture* operator()() const {return pTexture;}
    void swap(Texture& rhs) noexcept;
private:
    Rect rect;
    SDL_Texture* pTexture = nullptr;
};

#endif