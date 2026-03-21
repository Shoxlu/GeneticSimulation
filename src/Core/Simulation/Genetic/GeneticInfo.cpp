#include <Core/Simulation/Genetic/GeneticInfo.hpp>
GeneticInfo::GeneticInfo() : specie(-1)
{

}

void GeneticInfo::Random()
{
    size = Random::RandFloat(0, 3);
    speed = Random::RandFloat(0, 10);
    return;
}

void GeneticInfo::Mutate(double weight)
{
    size = std::max(0.0,Random::NormalWithdraw(size, weight));
    speed = std::max(0.0,Random::NormalWithdraw(speed, weight));
    //Color
}