#include <Graphic/Sprite/SpriteManager.hpp>

SpriteManager::SpriteManager(/* args */)
{
}

SpriteManager::~SpriteManager()
{
}

Sprite SpriteManager::CreateSprite(SDL_Renderer* renderer, const char *texture_name)
{
    Texture texture = LoadImage(renderer, texture_name);
    Sprite sprite(texture);
    return sprite;
}


void SpriteManager::DrawSprite(SDL_Renderer* rend, Vec pos, Sprite& sprite, float x_mult, float y_mult)
{
    SDL_FRect src = {.x = (float)(sprite.offset_texture.x),
                     .y = (float)(sprite.offset_texture.y),
                     .w = (float)(sprite.size.x),
                     .h = (float)(sprite.size.y)};
    DrawTexture(rend,
                pos + sprite.offset_draw,
                sprite.data,
                &src,
                x_mult,
                y_mult);
}