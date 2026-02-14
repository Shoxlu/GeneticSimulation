#include <Core/Simulation/Genetic/GeneticInfo.hpp>

GeneticInfo::GeneticInfo() : specie(0)
{

}

void GeneticInfo::Random()
{
    size = Random::RandFloat(0, 3);
    speed = Random::RandFloat(0, 10);
    return;
}