#include <Logic/Collision/CollisionManager.hpp>


bool CollisionManager::CollideRectToRect(Rect rec1, Rect rec2)
{
    return (rec1.pos.x < rec2.pos.x + rec2.size.x &&
        rec1.pos.x + rec1.size.x > rec2.pos.x &&
        rec1.pos.y < rec2.pos.y + rec2.size.y &&
        rec1.pos.y + rec1.size.y> rec2.pos.y);
}
bool CollisionManager::CollideCircleToCircle(Vec center1, double radius1, Vec center2, double radius2)
{
    double limit_distance = radius1 + radius2;
    return dist_sq(center1, center2) < (limit_distance * limit_distance);
}