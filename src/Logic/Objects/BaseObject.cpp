#include <Logic/Objects/BaseObject.hpp>
#include <Core/Engine.hpp>

//Constructeur pour BaseObject
BaseObject::BaseObject():pos(0, 0), is_active(true)
{
  
}

BaseObject::BaseObject(const Vec& pos_initial): pos(pos_initial), is_active(true)
{
  
}

//Destructeur pour BaseObject
BaseObject::~BaseObject(){
    log_printf("Delete BaseObject\n");
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


void BaseObject::SetSprite(const Sprite& new_sprite){
    sprite = new_sprite;
}

Sprite BaseObject::GetSprite() const{
    return sprite;
}

bool BaseObject::IsActive() const{
    return is_active;
}

void BaseObject::SetActivity(bool new_activity)
{
    is_active = new_activity;
}

void BaseObject::FreeRessources()
{
    DeleteDrawFunc(draw_id);
    sprite.FreeTexture();
}