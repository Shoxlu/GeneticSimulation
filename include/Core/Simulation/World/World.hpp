#pragma once
#include <Utils/utils.hpp>
#include <Logic/Objects/Fruit/Fruit.hpp>
#include <Logic/Objects/FitObject/FitObject.hpp>

class World
{

public:
    World();
    World(double w, double h);
    void AddObjectToWorld(FitObject obj);
    void AddObjectToWorld();
    void AddFruitToWorld(Fruit obj);
    void UpdateObjects(double dt);
    ~World();
protected:
    std::vector<Fruit> fruits;
    std::vector<FitObject> objects;
    double width;
    double height;

};
