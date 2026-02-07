#include <Core/Simulation/Genetic/Generation.h>
#include <Utils/utils.hpp>



Specie::Specie() 
{

}
Specie::~Specie() 
{

}
GeneticInfo Specie::Mutate() 
{ 

    return base_genes;
}

Generation::Generation() 
{

}
void Generation::NewGeneration() 
{

}
void Generation::EndGeneration(std::vector<FitObject>& objs) 
{
    UpdateSpeciesScores(objs);
    UpdateBestSpecie();
}


GeneticInfo Generation::CreateNewIndividual(size_t specie1, size_t specie2) { return GeneticInfo(); }
GeneticInfo Generation::CreateNewIndividual(GeneticInfo& obj1, GeneticInfo& obj2) { return GeneticInfo(); }
void Generation::UpdateSpecies(std::vector<FitObject>& objs) {}
Specie Generation::FindNewSpecie(GeneticInfo &genes) { return Specie(); }
void Generation::UpdateSpeciesScores(std::vector<FitObject>& objs)
{
    std::vector<int> n_indiv(species.size());
    for(FitObject& obj : objs)
    {
        species[obj.GetGenes().specie].average_fitness += obj.fitness;
    }
}
void Generation::UpdateBestSpecie() 
{
    Specie &best = best_specie;
    for(Specie& s : species)
    {
        if(s.average_fitness > best.average_fitness) // Maybe add a condition to break equalities
        {
            best = s;
        }
    }
    best_specie = best;
}
Specie Generation::GetBestSpecie() const
{
    return best_specie;
}

void Generation::SetBestSpecie(Specie &specie)
{
    best_specie = specie;
}