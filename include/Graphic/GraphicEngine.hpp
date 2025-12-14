#pragma once
#include <Graphic/Window/Window.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Texture/TextureManager.hpp>
#include <Graphic/Sprite/SpriteManager.hpp>
#include <Logic/Objects/Object.hpp>

class GraphicEngine: protected SpriteManager
{
private:

protected:
   
public:
    GraphicEngine();
    ~GraphicEngine();
    void UpdateWindow(Window& window);
    void UserRender();
    Texture GetTexture(Window& window, const char *path);
    Sprite CreateSprite(Window& window, const char *path);
    static void DrawSprite(Window& window, Vec pos, Sprite& sprite);
    static void DrawSprite(Window& window, Vec pos, Sprite& sprite, float x_mult, float y_mult);

};
