#include "Initializer.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Shape.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <cstdlib>

void Sync();

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    auto initializer = std::make_shared<Initializer>();
    const unsigned int windowWidth = 1280;
    const unsigned int windowHeight = 720;
    auto window = std::make_shared<Window>(initializer, windowWidth, windowHeight);
    auto renderer = std::make_shared<Renderer>(window);

    bool quit = false;
    SDL_Event event;

    Star stars[500];
    for(int i = 0; i < 500; ++i) {
        stars[i].Randomize(windowWidth, windowHeight);
    }

    while (!quit) {
        SDL_SetRenderDrawColor(renderer->Raw(), 32, 32, 32, 255);
	    SDL_RenderClear(renderer->Raw());

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEMOTION:
                if(SDL_GetMouseState(NULL, NULL) &SDL_BUTTON(1))
                    SDL_RenderDrawPoint(renderer->Raw(), event.motion.x, event.motion.y);
                break;
            }
        }

        for(int i = 0; i < 500; ++i) {
            renderer->Draw(stars[i]);
            stars[i].pos.x += stars[i].speed;
            if(stars[i].pos.x >= (int)windowWidth) {
                stars[i].pos.y = std::rand() % windowHeight;
                stars[i].pos.x %= windowWidth;
            }
        }

        SDL_RenderPresent(renderer->Raw());
        Sync();
    }

    return 0;
}

void Sync()
{
    static unsigned long tick = 0;

    unsigned long tock = SDL_GetTicks();
    unsigned long elapse = tock - tick;
    if(elapse < 33) {
        elapse = 33 - elapse;
    } else {
        elapse = 1;
    }
    tick = tock;

    SDL_Delay(elapse);
}
