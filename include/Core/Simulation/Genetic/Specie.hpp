#include <Core/Simulation/Genetic/GeneticInfo.hpp>

class Specie{
public:
    Specie();
    ~Specie();
    bool operator<(Specie& other){
        return average_fitness < other.average_fitness;
    }
    bool operator<=(Specie& other){
        return average_fitness <= other.average_fitness;
    }
    bool operator>=(Specie& other){
        return average_fitness >= other.average_fitness;
    }
    bool operator>(Specie& other){
        return average_fitness <= other.average_fitness;
    }
    bool operator==(Specie& other){
        return average_fitness == other.average_fitness;
    }
    GeneticInfo base_genes;
    int average_fitness;
    size_t n_indiv;
    size_t id;

private:

};