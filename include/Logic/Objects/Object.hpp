#pragma once
#include <Utils/utils.hpp>
#include <Logic/Objects/BaseObject.hpp>
#include <Graphic/Texture/Texture.hpp>

class Object: public BaseObject
{
private:
    Texture texture;
    Vec vel;
    Vec acc;

public:
    Object();
    Object(Vec pos_initial);
    Object(Vec pos_initial, Vec vel_initial);
    Object(Vec pos_initial, Vec vel_initial, Vec acc_initial);
    ~Object();
    void Update(double dt);
    void UpdatePos(double dt);
    void ClampToEdge(double x_min, double y_min, double x_max, double y_max);
};
