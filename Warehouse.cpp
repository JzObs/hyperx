#include "Warehouse.hpp"
#include "Logger.hpp"
#include <SDL2/SDL_image.h>

#ifndef HYPERX_ASSETS_PATH
#define HYPERX_ASSETS_PATH "../assets/"
#endif

Warehouse::Warehouse(std::shared_ptr<Renderer> renderer) : pRenderer(renderer)
{
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    Load();
}

Warehouse::~Warehouse()
{
    for(auto s : spriteArray) {
        SDL_FreeSurface(s);
    }

    IMG_Quit();
}

Texture Warehouse::GetTexture(WarehouseSprite enumeration)
{
    int i = static_cast<int>(enumeration);
    return Texture{pRenderer->Raw(), spriteArray.at(i)};
}

void Warehouse::Load()
{
    spriteArray.at(static_cast<int>(WarehouseSprite::background)) = IMG_Load(HYPERX_ASSETS_PATH "1.jpg");
    spriteArray.at(static_cast<int>(WarehouseSprite::cloud))      = IMG_Load(HYPERX_ASSETS_PATH "cloud.png");
}