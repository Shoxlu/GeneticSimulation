#include <Logic/Objects/BaseObject.hpp>

//Constructeur pour BaseObject
BaseObject::BaseObject():pos(0, 0)
{
  
}

BaseObject::BaseObject(const Vec& pos_initial): pos(pos_initial)
{
  
}

//Destructeur pour BaseObject
BaseObject::~BaseObject(){
}

//Actualise les caractéristiques de BaseObject
void BaseObject::Update(){
    
}

void BaseObject::SetPos(const Vec& new_pos){
    pos = new_pos;
}

Vec BaseObject::GetPos() const 
{
    return pos;
}