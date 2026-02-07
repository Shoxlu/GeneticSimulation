#pragma once
#include <vector>
#include <Logic/Objects/FitObject/FitObject.hpp>
#include <Core/Simulation/Genetic/GeneticInfo.hpp>


class Specie{
public:
    Specie();
    ~Specie();
    GeneticInfo Mutate();
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
private:

};

class Generation 
{
    public:
        Generation();
        std::vector<FitObject> FirstGeneration(size_t size);
        std::vector<FitObject> NewGenerationSimple(std::vector<FitObject> &old_generation);
        std::vector<FitObject> NewGeneration(std::vector<FitObject>& old_generation);
        void EndGeneration(std::vector<FitObject>& objs);
        //Create a new individual from the specie specie
        GeneticInfo CreateNewIndividual(size_t specie);
        //Create a child from a breed between specie1 and specie2
        GeneticInfo CreateNewIndividual(size_t specie1, size_t specie2);
        // Create a child from a breed between obj1 and obj2;
        GeneticInfo CreateNewIndividual(GeneticInfo& obj1, GeneticInfo& obj2);
        //Check all objects to determine their new specie, if it has changed
        //Updates the species table according to the modifications. Should be ran after mutations.
        void UpdateSpecies(std::vector<FitObject>& objs);
        void SortSpecies();
        //Determines to which specie the genes should belong
        //Creates a new one if it is too far from any known one
        Specie FindNewSpecie(GeneticInfo &genes);
        //Should be ran after the end of a generation
        void UpdateSpeciesScores(std::vector<FitObject>& objs);
        //Should be ran after the end of a generation
        void UpdateBestSpecie();


        Specie GetBestSpecie() const;
        void SetBestSpecie(Specie &specie);

        int GetAllFitness();

    private:
        std::vector<Specie> species;
        Specie best_specie;
};