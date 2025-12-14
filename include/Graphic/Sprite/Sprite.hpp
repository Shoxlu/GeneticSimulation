#pragma once
#include <Utils/utils.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Window/Window.hpp>

class Sprite: public Texture
{
private:
    void SetOffset(const Vec& );
public:
    Sprite();
    Sprite(Texture& texture);
    ~Sprite();
    void CenterAnchor();
    void Draw(Vec& pos);

    Vec offset_draw;
    Vec offset_texture;
    Vec size;
};

