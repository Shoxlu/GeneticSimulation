#pragma once
#include <Graphic/Sprite/Sprite.hpp>
#include <Graphic/Texture/TextureManager.hpp>

class SpriteManager : protected TextureManager
{
private:
    /* data */
protected:
    static void DrawSprite(Window& window, Vec pos, Sprite& sprite);
public:
    SpriteManager(/* args */);
    ~SpriteManager();
    Sprite CreateSprite(Window& window, const char* texture_name);
    static Sprite CreateEmptySprite(Window &window);
};


