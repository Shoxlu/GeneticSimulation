#pragma once
#include <Logic/Objects/BaseObject.hpp>
#include <Utils/utils.hpp>

class CollideObject:public BaseObject
{
public:
    CollideObject(const Vec &pos);

    //inutilisé
    bool isInGroup(size_t id);
    bool CanCollideWithGroup(size_t group_id);
    void SetGroupSrc(size_t id, bool value);
    void SetGroupDest(size_t id, bool value);

private:
    bool group_source[32]; //A quel groupe de collision l'objet appartient
    bool group_dest[32]; //Avec quel groupe je peux intéragir
 
};

class RectBox: public CollideObject
{
public:
    RectBox(const Rect &rect);
    Vec size;//La position est dupliquée...
};

class CircleBox: public CollideObject
{
public:
    CircleBox(const Vec& pos, const float radius);
    float radius;
};