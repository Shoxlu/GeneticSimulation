#include <Core/Simulation/Simulation.hpp>

Simulation::Simulation():World(0, 0), Engine(0, 0), dt(1)
{
    Random::Init();
}


Simulation::Simulation(int n_obj, double dt, double width, double height):
World(width, height), Engine(width, height), dt(dt)
{
    Random::Init();
    objects.resize(n_obj);
    ObjectManager::RandomizeSet(objects, Vec(0, width), Vec(0, height));
    for (size_t i = 0; i < objects.size(); i++)
    {
        Object &obj = objects[i];
        Vec pos = obj.GetPos();
        log_printf("%f, %f\n", pos.x, pos.y);
        obj.SetSprite(CreateSprite("../img/pawn.bmp"));
    }
}

Simulation::~Simulation()
{

}
    
void Simulation::Start()
{
    Main();
}

void Simulation::Main()
{
    while (!WindowClosed())
    {
        UpdateLogic();
        UpdateSimulation();
        DrawSimulation();
        UpdateGraphic();
    }
    log_printf("Fin de l'appli ?\n");
    TerminateWindow();
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
        obj.UpdatePos(dt);
        obj.ClampToEdge(0, 0, width, height);
    }
}

void Simulation::DrawObjects()
{
    for(Object& obj: objects){
        obj.Draw();
    }
}