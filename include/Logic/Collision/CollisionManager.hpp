#pragma once
#include <Utils/utils.hpp>
#include <Logic/Objects/CollideObject/CollideObject.hpp>

class CollisionManager
{
private:
    /* data */
public:
    static bool CollideRectToRect(const RectHitbox& rec1, const RectHitbox& rec2);
    static bool CollideCircleToCircle(const CircleHitbox&, const CircleHitbox&);
    
};

