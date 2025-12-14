#include <Graphic/Sprite/Sprite.hpp>
#include <Graphic/Texture/TextureManager.hpp>
#include <Graphic/GraphicEngine.hpp>

Sprite::Sprite():Texture(), offset_draw(0, 0), offset_texture(0, 0), src_size(0, 0), dst_size(0, 0), angle(0.0)
{

}

Sprite::Sprite(Texture& texture):Texture(texture), offset_draw(0, 0), offset_texture(0, 0), angle(0.0)
{
    float h, w;
    SDL_GetTextureSize(texture.data, &w, &h);
    src_size = Vec(w, h);
    dst_size = src_size;
}

Sprite::~Sprite()
{
}

void Sprite::SetAnchor(const Vec& new_offset){
    offset_draw = new_offset;
}

void Sprite::SetAnchor(double x, double y){
    offset_draw = Vec(x, y);
}

void Sprite::SetAngle(double new_angle){
    angle = new_angle;
}

void Sprite::TopLeftAnchor()
{
    SetAnchor(0, 0);
}

void Sprite::CenterAnchor()
{
    SetAnchor(-src_size.x / 2, -src_size.y / 2);
}

void Sprite::SetSrcSize(double w, double h)
{
    src_size = Vec(w, h);
}

void Sprite::SetDstSize(double w, double h)
{
    dst_size = Vec(w, h);
}

void Sprite::Draw(Vec& pos)
{
    GraphicEngine::DrawSprite(*window, pos, *this);
}