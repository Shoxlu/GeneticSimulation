#pragma once
#include <Core/Simulation/World/World.hpp>
#include <Logic/Objects/Object.hpp>
#include <Core/Engine.hpp>
#include <vector>

class Simulation: public World
{
private:
    double dt;
    std::vector<Object> objects;
    //peut-être que c'est inutile ?
    Engine& engine;
    Window &window;

public:
    Simulation(Window& window, const int n_obj,const double width,const double height,const double dt);
    ~Simulation();
    void UpdateObjects();
    void DrawObjects();
    void UpdateSimulation();
    void DrawSimulation();
};

