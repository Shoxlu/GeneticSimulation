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
    double angle;
    double angle_vel;
    bool angle_locked = false;

public:
    Object();
    Object(const Vec& pos_initial);
    Object(const Vec &pos_initial, const Vec &vel_initial);
    ~Object();
    void Update(double dt);
    void UpdateAngle(double dt);
    void UpdatePos(double dt);
    void ClampToEdge(double x_min, double y_min, double x_max, double y_max);
    //Bloque l'angle pour suivre la direction de l'object
    void LockAngle();
    void UnlockAngle();
    void Draw();
    
    void SetVel(const Vec& new_vel);
    Vec GetVel();

    void SetAcc(const Vec& new_acc);
    Vec GetAcc();

    void SetSprite(const Sprite& new_sprite);
    Sprite GetSprite();

    void SetAngleVel(double new_angle_vel);
    double GetAngleVel();

    void SetAngle(double new_angle);
    double GetAngle();
};
