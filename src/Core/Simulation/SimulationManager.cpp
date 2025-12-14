#include <Core/Simulation/SimulationManager.hpp>

SimulationManager::SimulationManager()
{
    Random::Init();
}


SimulationManager::~SimulationManager()
{

}
 
void SimulationManager::CreateSimulation(Window& window, int n_obj, double width, double height, double dt)
{
    simulations.emplace_back(window, n_obj, width, height, dt);
    DrawSimulations();
}

void SimulationManager::Update()
{
    UpdateSimulations();
    DrawSimulations();   
}

void SimulationManager::DrawSimulations()
{
    for(Simulation& simulation:simulations)
    {
        simulation.DrawSimulation();
    }
}


void SimulationManager::UpdateSimulations()
{
    for(Simulation& simulation:simulations)
    {
        simulation.UpdateSimulation();
    }
}