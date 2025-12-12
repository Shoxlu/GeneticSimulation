#pragma once
#include <Utils/Vec.hpp>

class BaseObject{
//Accessible par tous
public:
    BaseObject();
    BaseObject(Vec pos_initial);
    ~BaseObject();
    void Update();
    Vec pos;
//Accessible par les héritiers et soi-même
protected:
    
// Accessible par soi-même
private:
};