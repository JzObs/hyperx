#include "Scene.hpp"

Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height)
{
    for(auto& s : stars) {
        s.Randomize(width, height);
    }
}

void Scene::AddBackground(Texture&& texture)
{
    background = std::move(texture);
}

void Scene::AddCloud(Texture&& texture)
{
    cloud.texture = std::move(texture);
}

void Scene::Draw(Renderer& renderer)
{
    renderer.DrawEx(background);
    for(const auto& s : stars) {
        renderer.Draw(s);
    }
    renderer.Draw(cloud.texture);
}

void Scene::Advance(const unsigned int ms)
{
    for(auto& s : stars) {
        s.Move(ms, width, height);
    }
}
