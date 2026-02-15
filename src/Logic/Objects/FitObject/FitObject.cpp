#include <Logic/Objects/FitObject/FitObject.hpp>


FitObject::FitObject(/* args */)
{
}

FitObject::FitObject(const GeneticInfo& infos): genes(infos)
{

}

void FitObject::DoCollide(Fruit& fruit){
    if(!is_active || !fruit.IsActive())
        return;
    fitness++;
    log_printf("Obj %p a mangé le fruit %p\n", this, &fruit);
}


void FitObject::DoCollide(FitObject& obj){
    if(!is_active || !obj.IsActive())
        return;
    log_printf("Obj %p a collisionné avec l'obj %p\n", this, &obj);
}

void FitObject::Update(double dt)
{
    // log_printf("Hello From FitObject\n");

    //sprite.SetColor(genes.color);
    Object::Update(dt*genes.speed);//Well...

}

GeneticInfo FitObject::GetGenes() const
{
    return genes;
}

int FitObject::GetFitness() const
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