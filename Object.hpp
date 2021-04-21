#ifndef HYPERX_OBJECT_HPP
#define HYPERX_OBJECT_HPP

#include "Shape.hpp"
#include "Texture.hpp"

struct Star
{
    constexpr static float f_speed_constant = 33.0;
    Point pos;
    unsigned int speed, width, height;

    void Randomize(const unsigned int windowWidth, const unsigned int windowHeight);
    void Move(const unsigned int frameMs, const unsigned int windowWidth, const unsigned int windowHeight);
};

struct Cloud
{
    Texture texture;
    Rect rect;
};

#endif