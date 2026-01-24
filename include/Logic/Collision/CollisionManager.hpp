#pragma once
#include <Utils/utils.hpp>
#include <Logic/Objects/CollideObject/CollideObject.hpp>

class CollisionManager
{
private:
    /* data */
public:
    static bool CollideRectToRect(RectBox rec1, RectBox rec2);
    static bool CollideCircleToCircle(CircleBox, CircleBox);
    
};

