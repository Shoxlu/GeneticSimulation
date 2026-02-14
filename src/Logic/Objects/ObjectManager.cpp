#include <Logic/Objects/ObjectManager.hpp>
#include <Utils/DrawFunc/DrawFunc.hpp>

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}


std::vector<Object> ObjectManager::CreateRandomSet(const int n_obj,const Vec& x_range, const Vec& y_range)
{
    //La méthode est un peu nulle, elle recopie tous les objets au retour...
    std::vector<Object> objects(n_obj);
    RandomizeSet(objects, x_range, y_range);
    return objects;
}
void ObjectManager::RandomizeSet(std::vector<Object>& objects, const Vec& x_range, const Vec& y_range)
{
    for(Object& obj:objects){
        Vec pos = {Random::RandFloat(x_range.x, x_range.y), Random::RandFloat(y_range.x, y_range.y)};
        obj.SetPos(pos);
    }
}

void ObjectManager::SetObjSprite(Object& obj, Window& win, std::string path)
{
    Sprite sprite = Engine::Instance().CreateSprite(win, path.data());
    sprite.CenterAnchor();
    obj.SetSprite(sprite);
    obj.LockAngle();
}

void ObjectManager::SetCircleBox(Object& obj, float radius)
{
    CircleHitbox *c = new CircleHitbox(obj.GetPos(), radius);
    obj.SetHitbox(c);
}

void ObjectManager::SetCircleBox(FitObject& obj, float radius)
{
    CircleHitbox *c = new CircleHitbox(obj.GetPos(), radius);
    obj.SetHitbox(c);
}

void ObjectManager::SetRectBox(Object& obj, Vec& size)
{
    RectHitbox *r = new RectHitbox(Rect(obj.GetPos(), size));
    obj.SetHitbox(r);
}

void ObjectManager::SetRectBox(FitObject& obj, Vec& size)
{
    RectHitbox *r = new RectHitbox(Rect(obj.GetPos(), size));
    obj.SetHitbox(r);
}