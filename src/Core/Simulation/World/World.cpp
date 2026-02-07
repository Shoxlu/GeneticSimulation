#include <Core/Simulation/World/World.hpp>
#include <Logic/Objects/ObjectManager.hpp>



World::World():width(0), height(0)
{
}

World::World(double width, double height):width(width), height(height)
{
}


void World::AddObjectToWorld(FitObject& obj){
    objects.emplace_back(obj);
    AddToDrawQueue<FitObject>(objects[objects.size()-1]);
}

void World::AddObjectToWorld(){
    objects.emplace_back();
    AddToDrawQueue<FitObject>(objects[objects.size()-1]);
}


void World::AddFruitToWorld(Fruit& fruit)
{
    fruits.emplace_back(fruit);
    AddToDrawQueue<Fruit>(fruits[fruits.size()-1]);
}

void World::UpdateObjects(double dt)
{
    for(FitObject& obj: objects){
        obj.Update(dt);
        obj.ClampToEdge(0, 0, width, height);
    }
}

World::~World()
{
}