#include <Logic/Objects/Object.hpp>


Object::Object()
{
}

Object::Object(Vec pos_initial):
BaseObject(pos_initial)
{

}
Object::Object(Vec pos_initial, Vec vel_initial):
BaseObject(pos_initial), vel(vel_initial)
{
    
}

Object::Object(Vec pos_initial, Vec vel_initial, Vec acc_initial): 
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
