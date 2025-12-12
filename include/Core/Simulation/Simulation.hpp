#pragma once
#include <vector>
#include <Logic/Objects/Object.hpp>
#include <Logic/Objects/ObjectManager.hpp>
#include <Core/Simulation/World/World.hpp>
#include <Core/Engine.hpp>

class Simulation: protected World, public Engine
{
protected:
    std::vector<Object> objects;
    double dt;
public:
    Simulation();
    Simulation(int n_obj, double dt, double width, double height);
    ~Simulation();
    void Start();
    void Main();
    void UpdateSimulation();
    void DrawSimulation();
    void UpdateObjects();
    void DrawObjects();
};