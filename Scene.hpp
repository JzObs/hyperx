#pragma once

#ifndef HYPERX_SCENE_HPP
#define HYPERX_SCENE_HPP

#include "Object.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"
#include <array>

class Scene
{
public:
    Scene(unsigned int width, unsigned int height);
    void AddBackground(Texture&& texture);
    void AddCloud(Texture&& texture);
    void Draw(Renderer& renderer);
    void Advance(const unsigned int ms);
private:
    unsigned int width, height;
    Texture background;
    std::array<Star, 500> stars;
    Cloud cloud;
};

#endif