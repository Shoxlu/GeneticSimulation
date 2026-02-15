#pragma once
#include <Core/Simulation/World/World.hpp>
#include <Core/Engine.hpp>
#include <Core/Simulation/Genetic/Generation.hpp>
#include <vector>

#define MAX_SIMULATION_TIME 10

class Simulation: public World, public Generation
{
private:
    double dt; 
    //peut-être que c'est inutile ?
    Engine& engine;
    Window &window;
    double timer = 0;

public:
    Simulation(Window& window, const size_t n_obj,const double width,const double height,const double dt);
    ~Simulation();
    void UpdateSimulation();
    void DoCollisionsFruitAgent();
    void AddObjects(std::vector<FitObject> &objs);
    void StartNewGeneration();
    void SpawnFruits();
};

