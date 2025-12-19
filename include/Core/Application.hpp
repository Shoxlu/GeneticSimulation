#pragma once
#include <Core/Engine.hpp>
#include <Core/Simulation/SimulationManager.hpp>

class Application
{
private:
    Engine &engine;
    SimulationManager simManager;

public:
    Application(/* args */);
    ~Application();
    void Run();
};
