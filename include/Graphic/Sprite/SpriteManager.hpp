#pragma once
#include <Graphic/Sprite/Sprite.hpp>
#include <Graphic/Texture/TextureManager.hpp>

class SpriteManager : protected TextureManager
{
private:
    /* data */
public:
    SpriteManager(/* args */);
    ~SpriteManager();
    Sprite CreateSprite(SDL_Renderer* renderer, const char* texture_name);
    static void DrawSprite(SDL_Renderer* rend, Vec pos, Sprite& sprite, float x_mult, float y_mult);
};


