#pragma once
#include <Logic/Objects/BaseObject.hpp>
#include <Utils/utils.hpp>


class RectHitbox;
class CircleHitbox;

class Hitbox:public BaseObject
{
public:
    Hitbox(const Vec &pos);
    //inutilisé
    bool isInGroup(size_t id);
    bool CanCollideWithGroup(size_t group_id);
    void SetGroupSrc(size_t id, bool value);
    void SetGroupDest(size_t id, bool value);
    virtual bool Collide(const Hitbox &h) const = 0;
    virtual bool CollideWithRect(const RectHitbox &h) const = 0;
    virtual bool CollideWithCircle(const CircleHitbox &h) const = 0;

private:
    bool group_source[32]; //A quel groupe de collision l'objet appartient
    bool group_dest[32]; //Avec quel groupe je peux intéragir
 
};

class RectHitbox: public Hitbox
{
public:
    RectHitbox(const Rect &rect);

    bool Collide(const Hitbox &h) const;

    bool CollideWithRect(const RectHitbox &h) const;

    bool CollideWithCircle(const CircleHitbox &h) const;

    Vec size;//La position est dupliquée...
};

class CircleHitbox: public Hitbox
{
public:
    CircleHitbox(const Vec& pos, const float radius);

    bool Collide(const Hitbox &h) const;
    bool CollideWithRect(const RectHitbox &h) const;
    bool CollideWithCircle(const CircleHitbox &h) const;
    float radius;
};