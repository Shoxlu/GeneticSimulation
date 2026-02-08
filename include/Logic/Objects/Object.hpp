#pragma once
#include <Utils/utils.hpp>
#include <Logic/Objects/BaseObject.hpp>
#include <Logic/Objects/CollideObject/CollideObject.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Sprite/Sprite.hpp>

class Object: public BaseObject
{
private:
protected:
    Vec vel;
    Vec acc;
    double angle;
    double angle_vel;
    bool angle_locked = false;
    Hitbox *hitbox;

public:
    Object();
    Object(const Vec& pos_initial);
    Object(const Vec &pos_initial, const Vec &vel_initial);
    ~Object();
    void Update(double dt);
    void UpdateAngle(double dt);
    void UpdatePos(double dt);
    void UpdateHitbox();
    void ClampToEdge(double x_min, double y_min, double x_max, double y_max);
    //Bloque l'angle pour suivre la direction de l'object
    void LockAngle();
    void UnlockAngle();
    void Draw();
    
    void SetVel(const Vec& new_vel);
    Vec GetVel() const;

    void SetAcc(const Vec& new_acc);
    Vec GetAcc() const;

    void SetAngleVel(double new_angle_vel);
    double GetAngleVel() const;

    void SetAngle(double new_angle);
    double GetAngle() const;

    void SetHitbox(Hitbox *c);
    Hitbox *GetHitbox() const;
};
