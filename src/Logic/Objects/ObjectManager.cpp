#include <Logic/Objects/ObjectManager.hpp>


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
        obj.SetPos(Vec(Random::RandFloat(x_range.x, x_range.y), Random::RandFloat(y_range.x, y_range.y)));
    }
}
