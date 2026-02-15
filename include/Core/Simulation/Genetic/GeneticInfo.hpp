#pragma once
#include <cstdint>
#include "Utils/utils.hpp"

class GeneticInfo
{
private:

public:
    
    GeneticInfo();
    void Random();
    void Mutate(double weight);

    //Specie the genes derive from
    size_t specie;
    double speed = 1.0; //
    double size = 1.0; //only changes hitbox right now
    RGBA color; //(not implemented)

};
