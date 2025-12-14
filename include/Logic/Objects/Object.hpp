#pragma once
#include <Utils/utils.hpp>
#include <Logic/Objects/BaseObject.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Sprite/Sprite.hpp>

class Object: public BaseObject
{
private:
protected:
    Vec vel;
    Vec acc;
    Sprite sprite;
public:


    Object();
    Object(const Vec& pos_initial);
    Object(const Vec& pos_initial, const Vec& vel_initial);
    Object(const Vec& pos_initial, const Vec& vel_initial, const Vec& acc_initial);
    ~Object();
    void Update(double dt);
    void UpdatePos(double dt);
    void ClampToEdge(double x_min, double y_min, double x_max, double y_max);
    void Draw();

    void SetVel(const Vec& new_vel);
    Vec GetVel();

    void SetAcc(const Vec& new_acc);
    Vec GetAcc();

    void SetSprite(const Sprite& new_sprite);
    Sprite GetSprite();
};
