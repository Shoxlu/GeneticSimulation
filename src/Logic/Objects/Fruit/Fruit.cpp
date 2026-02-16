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
    SetActivity(false);
    log_printf("Le fruit %p a collisionné avec l'obj %p\n", this, &obj);
}

void Fruit::SetActivity(bool new_activity)
{
    is_active = new_activity;
    hitbox->SetActivity(new_activity);
}

Fruit::~Fruit()
{

}