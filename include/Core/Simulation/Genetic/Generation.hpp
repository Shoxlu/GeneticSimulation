#pragma once
#include <vector>
#include <Logic/Objects/FitObject/FitObject.hpp>
#include <Core/Simulation/Genetic/GeneticInfo.hpp>
#include <Core/Simulation/Genetic/Specie.hpp>

class Generation 
{
    public:
        Generation();
        std::vector<FitObject> FirstGeneration(size_t size);
        std::vector<FitObject> NewGenerationSimple(std::vector<FitObject> &old_generation);
        std::vector<FitObject> NewGeneration(std::vector<FitObject>& old_generation);
        void EndGeneration(std::vector<FitObject>& objs);
        //Create a new individual from the specie specie
        GeneticInfo CreateNewIndividual(int specie);
        //Create a child from a breed between specie1 and specie2
        GeneticInfo CreateNewIndividual(int specie1, int specie2);
        // Create a child from a breed between obj1 and obj2;
        GeneticInfo CreateNewIndividual(GeneticInfo& obj1, GeneticInfo& obj2);
        //Check all objects to determine their new specie, if it has changed
        //Updates the species table according to the modifications. Should be ran after mutations.
        void UpdateSpecies(std::vector<FitObject>& objs);
        void SortSpecies();
        //Determines to which specie the genes should belong
        //Creates a new one if it is too far from any known one
        Specie FindNewSpecie(GeneticInfo genes);
        //Should be ran after the end of a generation
        void UpdateSpeciesScores(std::vector<FitObject>& objs);
        //Should be ran after the end of a generation
        void UpdateBestSpecie();
        //Compute the score of proximity between a specie and some genes
        double SpecieScore(Specie &specie, GeneticInfo &genes);

        Specie GetBestSpecie() const;
        void SetBestSpecie(Specie &specie);

        double GetAllFitness();

    private:
    
        std::vector<Specie> species;
        Specie best_specie;
        int last_specie_id = -1;
};