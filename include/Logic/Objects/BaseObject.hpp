#pragma once
#include <Utils/Vec.hpp>

class BaseObject{
//Accessible par tout
public:
    BaseObject();
    BaseObject(Vec pos_initial);
    ~BaseObject();
    void Update();

//Accessible par les héritiers et soi-même
protected:
    Vec pos;
// Accessible par soi-même
private:
};