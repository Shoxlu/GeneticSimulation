#include <Logic/Objects/BaseObject.hpp>

//Constructeur pour BaseObject
BaseObject::BaseObject():pos(0, 0), is_active(true)
{
  
}

BaseObject::BaseObject(const Vec& pos_initial): pos(pos_initial), is_active(true)
{
  
}

//Destructeur pour BaseObject
BaseObject::~BaseObject(){
}

//Actualise les caractéristiques de BaseObject
void BaseObject::Update(double dt){
    if(!IsActive())
        return;
}

void BaseObject::SetPos(const Vec& new_pos){
    pos = new_pos;
}

Vec BaseObject::GetPos() const 
{
    return pos;
}

bool BaseObject::IsActive() const{
    return is_active;
}