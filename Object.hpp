#ifndef HYPERX_OBJECT_HPP
#define HYPERX_OBJECT_HPP

#include "Shape.hpp"

struct Star
{
    Point pos;
    unsigned int speed, width, height;

    void Randomize(unsigned int windowWidth, unsigned int windowHeight);
};

#endif