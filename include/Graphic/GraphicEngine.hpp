#pragma once
#include <Graphic/Window/Window.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Texture/TextureManager.hpp>


class GraphicEngine: public Window
{
private:
    TextureManager textureManager;
public:
    GraphicEngine(int width, int height);
    ~GraphicEngine();
    void UpdateGraphic();
    void UserRender();
    Texture GetTexture(const char *path);
};
