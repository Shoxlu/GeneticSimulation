#pragma once
#include <Utils/utils.hpp>
#include <Graphic/Texture/Texture.hpp>

class Sprite: public Texture
{
private:
    void SetOffset(const Vec& );
public:
    Sprite();
    ~Sprite();
    Sprite(Texture& texture);
    void Center();
    void Draw(Vec& pos);
    Vec offset_draw;
    Vec offset_texture;
    Vec size;
};

