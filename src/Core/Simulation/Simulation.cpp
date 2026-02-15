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
    std::vector<FitObject> to_add = FirstGeneration(n_obj);
    AddObjects(to_add);
    SpawnFruits();
}

Simulation::~Simulation()
{
    
}

void Simulation::SpawnFruits()
{
    Fruit fruit(Vec(300, 300));
    ObjectManager::SetObjSprite(fruit, window, "../img/fruit.bmp");
    ObjectManager::SetCircleBox(fruit, 20.0);
    fruit.GetHitbox()->SetSprite(SpriteManager::CreateEmptySprite(window));
    AddToDrawQueue<Hitbox>(*fruit.GetHitbox());
    AddFruitToWorld(fruit);
}

void Simulation::StartNewGeneration()
{
    log_printf("Start new_gen\n");
    timer = 0;
    //EndGeneration(objects);
    std::vector<FitObject> to_add = (objects);
    DeleteAllObjects();
    log_printf("Fin des delete d'objets\n");
    DeleteAllFruits();
    AddObjects(to_add);
    SpawnFruits();
}

void Simulation::AddObjects(std::vector<FitObject> &to_add)
{
    size_t n_obj = to_add.size();
    objects.reserve(n_obj);
    for (size_t i = 0; i < n_obj; i++)
    {
        FitObject& obj = to_add[i];
        obj.SetVel(Vec(Random::RandFloat(-1, 1), Random::RandFloat(-1, 1)));
        obj.SetPos(Vec(width / 2, height / 2));
        ObjectManager::SetObjSprite(obj, window, "../img/pawn.bmp");
        ObjectManager::SetCircleBox(obj, 20.0);
        obj.GetHitbox()->SetSprite(SpriteManager::CreateEmptySprite(window));
        AddToDrawQueue<Hitbox>(*obj.GetHitbox());
        Vec pos = obj.GetPos();
        log_printf("%f, %f\n", pos.x, pos.y);
        AddObjectToWorld(obj);
    }
}

void Simulation::DoCollisionsFruitAgent()
{
    for(FitObject& obj: objects){
        for(Fruit& fruit: fruits){
            //log_printf("Collision Check\n");
            Hitbox *hb_o = obj.GetHitbox();
            Hitbox *hb_f = fruit.GetHitbox();
            if (hb_o && hb_f && hb_o->Collide(*hb_f)){
                obj.DoCollide(fruit);
                fruit.DoCollide(obj);
            }
        }
    }
}

void Simulation::UpdateSimulation()
{
    //log_printf("Begin\n");
    DoCollisionsFruitAgent();
    UpdateObjects(dt);

    if(timer >= MAX_SIMULATION_TIME)
    {
        StartNewGeneration();
    }else{
        timer += dt;
    }
    //log_printf("End\n");
}

