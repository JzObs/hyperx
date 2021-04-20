#include "App.hpp"
#include <SDL2/SDL.h>

void App::Run()
{
    Configure();
    Loop();
}

void App::Configure()
{

}

void App::Loop()
{
    while(!GetQuit()) {
        ProcessEvent();
        if(pScene) {
            pRenderer->Prepare();       
            pScene->Draw(*pRenderer);
            pRenderer->Render();
            pScene->Advance(GetFrameMs());
        }
        Sync();
    }
}

void App::ProcessEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            SetQuit(true);
            break;
        case SDL_MOUSEMOTION:
            if(SDL_GetMouseState(NULL, NULL) &SDL_BUTTON(1))
                SDL_RenderDrawPoint(pRenderer->Raw(), event.motion.x, event.motion.y);
            break;
        default:
            break;
        }
    }
}

void App::Sync()
{
    static unsigned long tick = 0;

    unsigned long tock = SDL_GetTicks();
    unsigned long elapse = tock - tick;
    auto ms = GetFrameMs();
    if(elapse < ms) {
        elapse = ms - elapse;
    } else {
        elapse = 1;
    }
    tick = tock;

    SDL_Delay(elapse);
}