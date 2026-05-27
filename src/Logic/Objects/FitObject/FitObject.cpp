#include <Logic/Objects/FitObject/FitObject.hpp>


FitObject::FitObject(/* args */):fitness(0), genes(), can_eat(true)
{
}

FitObject::FitObject(const GeneticInfo& infos): fitness(0), genes(infos), can_eat(true)
{
}

void FitObject::DoCollide(Fruit& fruit){
    if(!is_active || !fruit.IsActive() || !can_eat)
        return;
    fitness+=10000;
    can_eat = false;
    log_printf("Obj %p a mangé le fruit %p\n", this, &fruit);
}


void FitObject::DoCollide(FitObject& obj){
    if(!is_active || !obj.IsActive())
        return;
    //log_printf("Obj %p a collisionné avec l'obj %p\n", this, &obj);
}

void FitObject::Update(double dt)
{
    // log_printf("Hello From FitObject\n");

    //sprite.SetColor(genes.color);
    Vec old_pos = pos;
    Object::Update(dt*genes.speed);//Well...
    fitness += dist_sq(old_pos+dt*genes.speed*vel, old_pos);
}

double FitObject::GetFitness() const
{
    return fitness;
}

void FitObject::SetHitbox(Hitbox* c)
{
    Object::SetHitbox(c);
    c->Resize(genes.size);
}

FitObject::~FitObject()
{

}