#pragma once 
#include <Logic/Objects/Object.hpp>


class Fruit:public Object
{
private:
    
public:
    Fruit();
    Fruit(const Vec& pos);
    void DoCollide(Object &obj);
    void SetActivity(bool new_activity);
    ~Fruit();
};


