#include <Core/Simulation/Simulation.hpp>

Simulation::Simulation():World(0, 0), Engine(0, 0), dt(1)
{

}
Simulation::Simulation(int n_obj, double dt, double width, double height):
World(width, height), Engine(width, height), dt(dt)
{
    objects.resize(n_obj);
    for (size_t i = 0; i < objects.size(); i++)
    {
        Object &obj = objects[i];
        obj.pos = Vec(30*i, 100);
        obj.vel = Vec(1, 0.8)/10;
        obj.texture = GetTexture("../img/pawn.bmp");
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
        DrawTexture(GetRenderer(), obj.pos, obj.texture.data);
    }
}