#include <Logic/Collision/CollisionManager.hpp>



bool CollisionManager::CollideRectToRect(const RectHitbox& rec1,const RectHitbox& rec2)
{
    Vec pos1 = rec1.GetPos();
    Vec pos2 = rec2.GetPos();
    return (pos1.x < pos2.x + rec2.size.x &&
        pos1.x + rec1.size.x > pos2.x &&
        pos1.y < pos2.y + rec2.size.y &&
        pos1.y + rec1.size.y> pos2.y);
}
bool CollisionManager::CollideCircleToCircle(const CircleHitbox& c1, const CircleHitbox& c2)
{
    double limit_distance = c1.radius + c2.radius;
    return dist_sq(c1.GetPos(), c2.GetPos()) < (limit_distance * limit_distance);
}