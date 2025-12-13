#pragma once
#include <Utils/Vec.hpp>

class BaseObject{
//Accessible par tous
public:
    BaseObject();
    BaseObject(const Vec& pos_initial);
    ~BaseObject();
    void Update();
    Vec GetPos();
    void SetPos(const Vec& new_pos);
    // Accessible par les héritiers et soi-même
protected:
    Vec pos;
// Accessible par soi-même
private:
};