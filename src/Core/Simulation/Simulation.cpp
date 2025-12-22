#include <Core/Simulation/Simulation.hpp>
#include <Logic/Objects/ObjectManager.hpp>
#include <Core/Engine.hpp>

Simulation::Simulation(Window& window, const size_t n_obj, const double width,const double height,const double dt):
World(width, height), dt(dt), engine(Engine::Instance()), window(window)
{
    //ObjectManager::RandomizeSet(objects, Vec(0, width), Vec(0, height));
    //C'est du code test.
    objects.reserve(n_obj);
    for (size_t i = 0; i < n_obj; i++)
    {
        FitObject obj;
        obj.SetVel(Vec(Random::RandFloat(-1, 1), Random::RandFloat(-1, 1)));
        obj.SetPos(Vec(width / 2, height / 2));
        Sprite sprite = engine.CreateSprite(window, "../img/pawn.bmp");
        sprite.CenterAnchor();
        obj.SetSprite(sprite);
        obj.LockAngle();
        AddObjectToWorld(obj);
        Vec pos = obj.GetPos();
        log_printf("%f, %f\n", pos.x, pos.y);
    }
    Fruit fruit(Vec(100, 100));
    Sprite sprite = engine.CreateSprite(window, "../img/fruit.bmp");
    sprite.CenterAnchor();
    fruit.SetSprite(sprite);
    AddFruitToWorld(fruit);
}

Simulation::~Simulation()
{
    
}

void Simulation::UpdateSimulation()
{
    UpdateObjects(dt);
}

