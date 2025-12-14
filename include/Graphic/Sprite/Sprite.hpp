#pragma once
#include <Utils/utils.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Window/Window.hpp>

class Sprite: public Texture
{
private:
    
public:
    Sprite();
    Sprite(Texture& texture);
    ~Sprite();
    void CenterAnchor();
    void TopLeftAnchor();
    void SetAnchor(const Vec& new_offset);
    void SetAnchor(double x, double y);
    void SetAngle(double angle);
    void SetSrcSize(double w, double h);
    void SetDstSize(double w, double h);
    void Draw(Vec& pos);

    Vec offset_draw;
    Vec offset_texture;
    Vec src_size;
    Vec dst_size;
    double angle;
};

