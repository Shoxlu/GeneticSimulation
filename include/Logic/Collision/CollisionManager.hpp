#pragma once
#include <Utils/utils.hpp>

class CollisionManager
{
private:
    /* data */
public:
    static bool CollideRectToRect(Rect rec1, Rect rec2);
    static bool CollideCircleToCircle(Vec center1, double radius1, Vec center2, double radius2);

};

