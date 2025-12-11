#pragma once
#include <vector>
#include <Logic/Objects/Object.hpp>
#include <Logic/Simulation/World/World.hpp>

class Simulation: protected World
{
private:
    std::vector<Object> objects;
    double dt;
public:
    Simulation();
    Simulation(int n_obj, double dt, double width, double height);
    ~Simulation();
    void Update();
};