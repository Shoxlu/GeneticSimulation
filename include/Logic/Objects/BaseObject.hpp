#pragma once
#include <Utils/Vec.hpp>

class BaseObject{
//Accessible par tous
public:
    BaseObject();
    BaseObject(const Vec& pos_initial);
    ~BaseObject();
    virtual void Update(double dt);
    bool IsActive() const;
    virtual Vec GetPos() const;
    virtual void SetPos(const Vec& new_pos);
    // Accessible par les héritiers et soi-même
protected:
    Vec pos;
    bool is_active;
    // Accessible par soi-même
private:
};