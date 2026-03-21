#include <Core/Simulation/Genetic/GeneticInfo.hpp>

class Specie{
public:
    GeneticInfo base_genes;
    double average_fitness;
    size_t n_indiv;
    int id;
    size_t all_time_indiv;
    Specie() : base_genes(), average_fitness(0), n_indiv(0), id(-1), all_time_indiv(0)
    {

    }
    ~Specie() 
    {

    }
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


private:

};