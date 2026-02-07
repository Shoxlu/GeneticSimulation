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


FitObject::~FitObject()
{
}