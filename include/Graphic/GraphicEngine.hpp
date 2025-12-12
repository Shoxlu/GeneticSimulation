#pragma once
#include <Graphic/Window/Window.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Texture/TextureManager.hpp>
#include <Logic/Objects/Object.hpp>

class GraphicEngine: protected Window, protected TextureManager
{
private:

public:
    GraphicEngine(int width, int height);
    ~GraphicEngine();
    void UpdateGraphic();
    void UserRender();
    Texture GetTexture(const char *path);
    void RenderObjects();
};
