#include <Graphic/Sprite/Sprite.hpp>
#include <Graphic/Texture/TextureManager.hpp>
#include <Graphic/GraphicEngine.hpp>

Sprite::Sprite():Texture(), offset_draw(0, 0), offset_texture(0, 0), size(0, 0)
{

}

Sprite::Sprite(Texture& texture):Texture(texture), offset_draw(0, 0), offset_texture(0, 0)
{
    float h, w;
    SDL_GetTextureSize(texture.data, &w, &h);
    size = Vec(w, h);
}

Sprite::~Sprite()
{
}

void Sprite::CenterAnchor()
{
    offset_draw = Vec(-size.x / 2, -size.y / 2);
}

void Sprite::Draw(Vec& pos)
{
    GraphicEngine::DrawSprite(*window, pos, *this);
}