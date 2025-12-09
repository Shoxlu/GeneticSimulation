#pragma once

class BaseObject{
//Accessible par tout
public:
    BaseObject();
    ~BaseObject();
    void Update();
//Accessible par les héritiers et soi-même
protected:
//Accessible par soi-même
private:
};