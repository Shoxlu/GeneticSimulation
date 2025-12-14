#include <Core/Simulation/Simulation.hpp>
#include <Logic/Objects/ObjectManager.hpp>
#include <Core/Engine.hpp>

Simulation::Simulation(Window& window, const int n_obj, const double width,const double height,const double dt):
World(width, height), dt(dt),objects(n_obj), engine(Engine::Instance()), window(window)
{
    ObjectManager::RandomizeSet(objects, Vec(0, width), Vec(0, height));
    for (size_t i = 0; i < objects.size(); i++)
    {
        Object &obj = objects[i];
        obj.SetVel(Vec(Random::RandFloat(-1, 1), Random::RandFloat(-1, 1)));
        //obj.SetPos(Vec(width / 2, height / 2));
        Sprite sprite = engine.CreateSprite(window, "../img/pawn.bmp");
        sprite.CenterAnchor();
        obj.SetSprite(sprite);
        obj.LockAngle();
        Vec pos = obj.GetPos();
        log_printf("%f, %f\n", pos.x, pos.y);
    }
}

Simulation::~Simulation()
{
}


void Simulation::UpdateSimulation()
{
    UpdateObjects();
}

void Simulation::DrawSimulation()
{
    DrawObjects();
}

void Simulation::UpdateObjects()
{
    for(Object& obj: objects){
        obj.Update(dt);
        obj.ClampToEdge(0, 0, width, height);
    }
}

void Simulation::DrawObjects()
{
    for(Object& obj: objects){
        obj.Draw();
    }
}