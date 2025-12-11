#pragma once
#include <Utils/utils.hpp>


class World
{

public:
    World();
    World(double width, double height);
    ~World();
protected:
    // std::vector<Fruit> fruits;
    double width;
    double height;

};
