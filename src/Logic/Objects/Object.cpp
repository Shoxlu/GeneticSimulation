#include <Logic/Objects/Object.hpp>
#include <Graphic/GraphicEngine.hpp>

Object::Object():hitbox(nullptr)
{
}

Object::Object(const Vec& pos_initial):
BaseObject(pos_initial),hitbox(nullptr)
{

}
Object::Object(const Vec& pos_initial, const Vec& vel_initial):
BaseObject(pos_initial), vel(vel_initial),hitbox(nullptr)
{
    
}


Object::~Object()
{
    printf("Delete Object\n");
    // if(hitbox) Memory leak
    //     delete hitbox;
}

void Object::UpdateAngle(double dt)
{
    if(angle_locked)
    {
        SetAngle(atan2(vel.y, vel.x));
    }else{
        SetAngle(angle + angle_vel * dt);
    }
}

void Object::LockAngle(){
    angle_locked = true;
}

void Object::UnlockAngle(){
    angle_locked = false;
}


void Object::Update(double dt)
{
    UpdatePos(dt);
    UpdateAngle(dt);
    UpdateHitbox();
}

void Object::UpdateHitbox()
{
    if(hitbox)
    {
        hitbox->SetPos(pos);
        // hitbox->SetAngle(angle);
    }
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

void Object::SetAngleVel(double new_angle_vel){
    angle_vel = new_angle_vel;
}

double Object::GetAngleVel(){
    return angle_vel;
}

void Object::SetAngle(double new_angle){
    angle = normalize_angle(new_angle);
    sprite.SetAngle(deg(angle));
}

double Object::GetAngle(){
    return angle;
}

void Object::SetHitbox(CollideObject* c)
{
    hitbox = c;
}

CollideObject* Object::GetHitbox()
{
    return hitbox;
}

void Object::Draw()
{
    sprite.Draw(pos);
}

