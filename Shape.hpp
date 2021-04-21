#ifndef HYPERX_SHAPE_HPP
#define HYPERX_SHAPE_HPP

struct Point
{
    float x, y;
};

struct Line
{
    float x1, y1, x2, y2;
};

struct Rect
{
    float x, y;
    int w, h;
};

#endif