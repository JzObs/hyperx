#include "Object.hpp"
#include <cstdlib>

void Star::Randomize(unsigned int windowWidth, unsigned int windowHeight)
{
    pos = {(float)(std::rand() % (int)windowWidth), (float)(std::rand() % (int)windowHeight)};
    speed = 1 + std::rand() % 8;
    height = 1 + std::rand() % 3;
    if(speed <= 2) {
        width = height;
    } else if(speed <= 5) {
        width = height * 2;
    } else {
        width = height * 3;
    }
}