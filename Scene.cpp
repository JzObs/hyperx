#include "Scene.hpp"

Scene::Scene(unsigned int width, unsigned int height) : width(width), height(height)
{
    for(auto& s : stars) {
        s.Randomize(width, height);
    }
}

void Scene::AddBackground()
{

}

void Scene::Draw(Renderer& renderer)
{
    renderer.Draw(background);
    for(const auto& s : stars) {
        renderer.Draw(s);
    }
}

void Scene::Advance(const unsigned int ms)
{
    for(auto& s : stars) {
        s.Move(ms, width, height);
    }
}
