#pragma once
#include <Utils/utils.hpp>


class World
{

public:
    World();
    World(double, double);
    ~World();
protected:
    // std::vector<Fruit> fruits;
    double width;
    double height;

};
