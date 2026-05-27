#include <Core/Simulation/Genetic/GeneticInfo.hpp>
GeneticInfo::GeneticInfo() : specie(-1)
{

}

void GeneticInfo::Random()
{
    //size = Random::RandFloat(0, 1);
    speed = Random::RandFloat(0, 1);
    starting_angle= Random::RandFloat(-M_PI, M_PI);
    return;
}

void GeneticInfo::Mutate(double weight)
{
    //size = abs(Random::NormalWithdraw(size, weight));
    speed = abs(Random::NormalWithdraw(speed, weight));
    starting_angle = Random::NormalWithdraw(starting_angle, M_PI/8);

    //Color
}