#include <Core/Simulation/Simulation.hpp>
#include <Logic/Objects/ObjectManager.hpp>
#include <Logic/Collision/CollisionManager.hpp>
#include <Core/Engine.hpp>

Simulation::Simulation(Window& window, const size_t n_obj, const double width,const double height,const double dt):
World(width, height), dt(dt), engine(Engine::Instance()), window(window)
{
    //ObjectManager::RandomizeSet(objects, Vec(0, width), Vec(0, height));
    //C'est du code test.
    objects.reserve(n_obj);
    for (size_t i = 0; i < n_obj; i++)
    {
        printf("Avant\n");
        AddObjectToWorld();
        printf("Apres\n");
        FitObject& obj = objects[i];
        obj.SetVel(Vec(Random::RandFloat(-1, 1), Random::RandFloat(-1, 1)));
        obj.SetPos(Vec(width / 2, height / 2));
        printf("SetSprite\n");
        ObjectManager::SetObjSprite(obj, window, "../img/pawn.bmp");
        printf("SetHitbox\n");
        ObjectManager::SetCircleBox(obj, 20.0);
        Vec pos = obj.GetPos();
        log_printf("%f, %f\n", pos.x, pos.y);
    }
    Fruit fruit(Vec(300, 300));
    ObjectManager::SetObjSprite(fruit, window, "../img/fruit.bmp");
    ObjectManager::SetCircleBox(fruit, 20.0);
    AddFruitToWorld(fruit);
}

Simulation::~Simulation()
{
    
}

void Simulation::DoCollisionsFruitAgent()
{
    for(FitObject& obj: objects){
        for(Fruit& fruit: fruits){
            if (obj.GetHitbox()->Collide(*fruit.GetHitbox())){
                printf("Collision\n");
            }
        }
    }
}

void Simulation::UpdateSimulation()
{
    DoCollisionsFruitAgent();
    UpdateObjects(dt);
}

