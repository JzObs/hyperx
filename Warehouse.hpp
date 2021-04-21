#ifndef HYPERX_WAREHOUSE_HPP
#define HYPERX_WAREHOUSE_HPP

#include "Renderer.hpp"
#include "Object.hpp"
#include "Texture.hpp"
#include <string>
#include <array>

enum struct WarehouseSprite : int
{
    begin = -1,
    background,
    cloud,
    end
};

struct SDL_Surface;
class Warehouse
{
public:
    Warehouse(std::shared_ptr<Renderer> renderer);
    ~Warehouse();

    Texture GetTexture(WarehouseSprite enumeration);

private:
    void Load();
    std::shared_ptr<Renderer> pRenderer;
    std::array<SDL_Surface*, static_cast<int>(WarehouseSprite::end)> spriteArray{nullptr};
};

#endif