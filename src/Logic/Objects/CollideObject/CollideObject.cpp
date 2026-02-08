#include <Logic/Objects/CollideObject/CollideObject.hpp>
#include <Logic/Collision/CollisionManager.hpp>
#include <Core/Engine.hpp>


Hitbox::Hitbox(const Vec& pos):BaseObject(pos)
{

}

Hitbox::~Hitbox()
{
    
}

bool Hitbox::CanCollideWithGroup(size_t id){
    return group_dest[id];
}

bool Hitbox::isInGroup(size_t id){
    return group_source[id];
}

void Hitbox::SetGroupDest(size_t id, bool value)
{
    group_dest[id] = value;
}
void Hitbox::SetGroupSrc(size_t id, bool value)
{
    group_source[id] = value;
}

CircleHitbox::CircleHitbox(const Vec &pos,const float radius): Hitbox(pos), radius(radius)
{

}

RectHitbox::RectHitbox(const Rect& rect): Hitbox(rect.pos), size(rect.size)
{
    
}

bool RectHitbox::Collide(const Hitbox &h) const
{
    return h.CollideWithRect(*this);
}

bool RectHitbox::CollideWithRect(const RectHitbox &h) const
{
    return CollisionManager::CollideRectToRect(*this, h);  
}


bool RectHitbox::CollideWithCircle(const CircleHitbox &h) const
{
    /*TODO: Implémenter Rect-Cirle collision*/
    Vec a = h.GetPos();
    return true;
}

void RectHitbox::Draw()
{
    if(!is_active)
        return;
    log_printf("La fonction de rendu pour RectHitbox n'est pas implémentée.\n");
}

bool CircleHitbox::Collide(const Hitbox &h) const
{
    return h.CollideWithCircle(*this);
}

bool CircleHitbox::CollideWithRect(const RectHitbox &h) const
{
    return h.CollideWithCircle(*this);
}

bool CircleHitbox::CollideWithCircle(const CircleHitbox &h) const
{
    return CollisionManager::CollideCircleToCircle(*this, h);
}

void CircleHitbox::Draw()
{
    if(!is_active)
        return;
    Engine::DrawCircle(sprite.GetWindow(), pos, radius, RGBA{255, 255, 0, 255});
}