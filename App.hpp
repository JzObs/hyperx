#pragma once

#ifndef HYPERX_APP_HPP
#define HYPERX_APP_HPP

#include "Renderer.hpp"
#include "Scene.hpp"

class App
{
public:
    App(std::shared_ptr<Renderer> renderer) : pRenderer(renderer) {}
    void Run();
    void SelectScene(std::shared_ptr<Scene> scene) {pScene.swap(scene);}
    void ResetScene() {pScene.reset();}
private:
    void Configure();
    void Loop();
    void ProcessEvent();
    void Sync();

    std::shared_ptr<Renderer> pRenderer;
    std::shared_ptr<Scene> pScene;

    bool quit = false;
    void SetQuit(const bool b) {quit = b;}
    bool GetQuit() {return quit;}

    unsigned int frameMs = 16;
    void SetFrameMs(const unsigned int ms) {frameMs = (ms > 16 ? ms : 16);}
    unsigned int GetFrameMs() {return frameMs > 16 ? frameMs : 16;}
};

#endif