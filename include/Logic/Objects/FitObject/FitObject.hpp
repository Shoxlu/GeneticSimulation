#pragma once
#include <Logic/Objects/Object.hpp>
#include <Logic/Objects/Fruit/Fruit.hpp>
#include <Core/Simulation/Genetic/GeneticInfo.hpp>

class FitObject: public Object
{
private:
    int fitness;
    GeneticInfo genes;

public:
    FitObject();
    void DoCollide(Fruit& fruit);
    void DoCollide(FitObject& fruit);
    FitObject(const GeneticInfo& infos);
    ~FitObject();

};

