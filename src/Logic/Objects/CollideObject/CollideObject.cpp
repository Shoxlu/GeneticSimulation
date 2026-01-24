#include <Logic/Objects/CollideObject/CollideObject.hpp>

CollideObject::CollideObject(const Vec& pos):BaseObject(pos)
{

}

bool CollideObject::CanCollideWithGroup(size_t id){
    return group_dest[id];
}

bool CollideObject::isInGroup(size_t id){
    return group_source[id];
}

void CollideObject::SetGroupDest(size_t id, bool value)
{
    group_dest[id] = value;
}
void CollideObject::SetGroupSrc(size_t id, bool value)
{
    group_source[id] = value;
}

CircleBox::CircleBox(const Vec &pos,const float radius): CollideObject(pos), radius(radius)
{

}

RectBox::RectBox(const Rect& rect): CollideObject(rect.pos), size(rect.size)
{
    
}