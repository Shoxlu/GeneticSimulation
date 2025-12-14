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


void SpriteManager::DrawSprite(Window& window, Vec pos, Sprite& sprite)
{
    SDL_FRect src = {.x = (float)(sprite.offset_texture.x),
                     .y = (float)(sprite.offset_texture.y),
                     .w = (float)(sprite.src_size.x),
                     .h = (float)(sprite.src_size.y)};
    SDL_FRect dest = {.x = (float)(pos.x+sprite.offset_draw.x),
                      .y = (float)(pos.y+sprite.offset_draw.y),
                      .w = (float)(sprite.dst_size.x),
                      .h = (float)(sprite.dst_size.y)};
    DrawTexture(window,
                sprite.data,
                &src,
                &dest, 
                sprite.angle);
}