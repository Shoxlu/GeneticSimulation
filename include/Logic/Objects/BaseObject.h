#pragma once

class BaseObject{
//Accessible by everyone
public:
    BaseObject();
    ~BaseObject();
    void Update();
//Accessible by only the inheriters and itself
protected:
//Accessible by only itself
private:
};