#pragma once
#include <Utils/Vec.hpp>
#include <Graphic/Sprite/Sprite.hpp>

class BaseObject{
//Accessible par tous
public:
    BaseObject();
    BaseObject(const Vec& pos_initial);
    ~BaseObject();
    virtual void Update(double dt);
    bool IsActive() const;
    virtual void SetActivity(bool new_activity);
    virtual Vec GetPos() const;
    virtual void SetPos(const Vec& new_pos);
    void SetSprite(const Sprite& new_sprite);
    Sprite GetSprite() const;

    // Accessible par les héritiers et soi-même
protected:
    Vec pos;
    bool is_active;
    Sprite sprite;

    // Accessible par soi-même
private:
};