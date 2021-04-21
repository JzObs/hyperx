#include "Initializer.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Shape.hpp"
#include "Warehouse.hpp"
#include "App.hpp"
#include "Logger.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <cstdlib>

void Sync(const unsigned int frameMs);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    auto initializer = std::make_shared<Initializer>();
    const unsigned int windowWidth = 1280;
    const unsigned int windowHeight = 720;
    auto window = std::make_shared<Window>(initializer, windowWidth, windowHeight);
    auto renderer = std::make_shared<Renderer>(window);
    auto warehouse = std::make_shared<Warehouse>(renderer);
    auto app = std::make_shared<App>(renderer);

    auto scene = std::make_shared<Scene>(windowWidth, windowHeight);
    scene->AddBackground(warehouse->GetTexture(WarehouseSprite::background));
    scene->AddCloud(warehouse->GetTexture(WarehouseSprite::cloud));
    app->SelectScene(scene);
    app->Run();

    return 0;
}