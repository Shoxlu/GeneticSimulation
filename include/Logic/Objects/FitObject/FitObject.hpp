#pragma once
#include <Logic/Objects/Object.hpp>
#include <Core/Simulation/Genetic/GeneticInfo.hpp>

class FitObject: public Object
{
private:
    int fitness;
    GeneticInfo genes;

public:
    FitObject();
    FitObject(const GeneticInfo& infos);
    ~FitObject();

};

