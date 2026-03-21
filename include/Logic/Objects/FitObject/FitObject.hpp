#pragma once
#include <Logic/Objects/Object.hpp>
#include <Logic/Objects/Fruit/Fruit.hpp>
#include <Core/Simulation/Genetic/GeneticInfo.hpp>

class FitObject: public Object
{
private:
    double fitness;

public:
    GeneticInfo genes;
    FitObject();
    FitObject(const GeneticInfo& infos);
    void DoCollide(Fruit& fruit);
    void DoCollide(FitObject& fruit);
    void Update(double dt);

    double GetFitness() const;

    void SetHitbox(Hitbox *c);

    ~FitObject();
    bool operator<(FitObject& obj)
    {
        return fitness < obj.GetFitness();
    }
    bool operator<=(FitObject& obj)
    {
        return fitness <= obj.GetFitness();
    }
    bool operator>=(FitObject& obj)
    {
        return fitness >= obj.GetFitness();
    }
    bool operator>(FitObject& obj)
    {
        return fitness > obj.GetFitness();
    }
    bool operator==(FitObject& obj)
    {
        return fitness == obj.GetFitness();
    }

};

