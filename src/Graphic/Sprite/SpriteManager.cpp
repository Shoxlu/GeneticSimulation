#include <Graphic/Sprite/SpriteManager.hpp>

SpriteManager::SpriteManager(/* args */)
{
}

SpriteManager::~SpriteManager()
{
}

Sprite SpriteManager::CreateSprite(Window& window, const char *texture_name)
{
    Texture texture = LoadImage(window, texture_name);
    Sprite sprite(texture);
    return sprite;
}


void SpriteManager::DrawSprite(Window& window, Vec pos, Sprite& sprite, float x_mult, float y_mult)
{
    SDL_FRect src = {.x = (float)(sprite.offset_texture.x),
                     .y = (float)(sprite.offset_texture.y),
                     .w = (float)(sprite.size.x),
                     .h = (float)(sprite.size.y)};
    DrawTexture(window,
                pos + sprite.offset_draw,
                sprite.data,
                &src,
                x_mult,
                y_mult);
}