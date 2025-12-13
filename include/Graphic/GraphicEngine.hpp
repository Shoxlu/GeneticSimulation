#pragma once
#include <Graphic/Window/Window.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Texture/TextureManager.hpp>
#include <Graphic/Sprite/SpriteManager.hpp>
#include <Logic/Objects/Object.hpp>

class GraphicEngine: protected Window, protected SpriteManager
{
private:

public:
    GraphicEngine(int width, int height);
    ~GraphicEngine();
    void UpdateGraphic();
    void UserRender();
    Texture GetTexture(const char *path);
    Sprite CreateSprite(const char *path);
    void RenderObjects();
    static void DrawSprite(Vec pos, Sprite& sprite);
    static void DrawSprite(Vec pos, Sprite& sprite, float x_mult, float y_mult);

};
