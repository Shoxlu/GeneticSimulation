#pragma once
#include <Graphic/Sprite/Sprite.hpp>
#include <Graphic/Texture/TextureManager.hpp>

class SpriteManager : protected TextureManager
{
private:
    /* data */
protected:
    static void DrawSprite(Window& window, Vec pos, Sprite& sprite, float x_mult, float y_mult);
public:
    SpriteManager(/* args */);
    ~SpriteManager();
    Sprite CreateSprite(Window& window, const char* texture_name);
   
};


