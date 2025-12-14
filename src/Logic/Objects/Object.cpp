#include <Logic/Objects/Object.hpp>
#include <Graphic/GraphicEngine.hpp>

Object::Object()
{
}

Object::Object(const Vec& pos_initial):
BaseObject(pos_initial)
{

}
Object::Object(const Vec& pos_initial, const Vec& vel_initial):
BaseObject(pos_initial), vel(vel_initial)
{
    
}

Object::Object(const Vec& pos_initial, const Vec& vel_initial, const Vec& acc_initial): 
BaseObject(pos_initial), vel(vel_initial), acc(acc_initial)
{
}


Object::~Object()
{
}


void Object::UpdatePos(double dt)
{
    //Méthode d'Euler (pas besoin de précision)
    vel += dt * acc;
    pos += dt * vel;
    acc = Vec(0, 0);
}

void Object::ClampToEdge(double x_min, double y_min, double x_max, double y_max)
{
    pos.x = std::max(x_min, pos.x);
    pos.y = std::max(y_min, pos.y);
    pos.x = std::min(x_max, pos.x);
    pos.y = std::min(y_max, pos.y);
}

void Object::SetVel(const Vec& new_vel){
    vel = new_vel;
}

void Object::SetAcc(const Vec& new_acc){
    acc = new_acc;
}

void Object::SetSprite(const Sprite& new_sprite){
    sprite = new_sprite;
}

Vec Object::GetVel(){
    return vel;
}

Vec Object::GetAcc(){
    return acc;
}

Sprite Object::GetSprite(){
    return sprite;
}


void Object::Draw()
{
    sprite.Draw(pos);
}