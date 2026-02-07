#include <Logic/Objects/Fruit/Fruit.hpp>


Fruit::Fruit()
{
    
}

Fruit::Fruit(const Vec& pos) : Object(pos)
{

}

void Fruit::DoCollide(Object &obj)
{
    if(!is_active)
        return;
    is_active = false;
    printf("Le fruit %p a collisionné avec l'obj %p\n", this, &obj);
}

Fruit::~Fruit()
{

}