#pragma once
#include <vector>
#include <Logic/Objects/Object.hpp>
#include <Logic/Objects/ObjectManager.hpp>
#include <Core/Simulation/World/World.hpp>
#include <Core/Simulation/Simulation.hpp>
#include <Core/Engine.hpp>

class SimulationManager
{
protected:
    std::vector<Simulation> simulations;
public:
    SimulationManager();
    ~SimulationManager();
    void CreateSimulation(Window& window, int n_obj, double width, double height, double dt);
    void Update();
    void UpdateSimulations();
    void DrawSimulations();
};