#include <Core/Simulation/Genetic/Generation.hpp>
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

std::vector<FitObject> Generation::FirstGeneration(size_t size) 
{
    std::vector<FitObject> new_objs;
    GeneticInfo adam, eve;
    adam.Random();
    eve.Random();
    for (size_t i = 0; i < size; i++)
    {
        GeneticInfo genes = CreateNewIndividual(adam, eve);
        new_objs.emplace_back(genes);
    }
    return new_objs;
}

std::vector<FitObject> Generation::NewGeneration(std::vector<FitObject>& old_generation) 
{
    std::vector<FitObject> new_objs;

}

std::vector<FitObject> Generation::NewGenerationSimple(std::vector<FitObject>& old_generation) 
{
    std::vector<FitObject> new_objs;
    size_t size = old_generation.size();
    int all_fitness = GetAllFitness();
    int count = 0;
    for (size_t i = 0; i < species.size(); i++)
    {
        Specie &s = species[i];
        int n_indiv = (int)round(size * (float)s.average_fitness / all_fitness);
        for (int i = 0; i < n_indiv; i++)
        {
            GeneticInfo genes = CreateNewIndividual(i);
            new_objs.emplace_back(genes);
            count++;
        }
        if(count >= size)
            break;
    }
    return new_objs;
}

void Generation::EndGeneration(std::vector<FitObject>& objs) 
{
    UpdateSpeciesScores(objs);
    SortSpecies();
    UpdateBestSpecie();
}

GeneticInfo Generation::CreateNewIndividual(size_t specie) 
{
    return GeneticInfo();
}

//The new individual gets half the specs of the first and second specie
GeneticInfo Generation::CreateNewIndividual(size_t specie1, size_t specie2) 
{
    return GeneticInfo();
}
//The new individual gets half the specs of the first and second parent
GeneticInfo Generation::CreateNewIndividual(GeneticInfo& obj1, GeneticInfo& obj2) 
{
    return GeneticInfo();
}

void Generation::UpdateSpecies(std::vector<FitObject>& objs) 
{

}

Specie Generation::FindNewSpecie(GeneticInfo &genes) 
{ 
    return Specie();
}

//The new average fitness is based on the old one (it's a choice, maybe change that later)
void Generation::UpdateSpeciesScores(std::vector<FitObject>& objs)
{
    for(Specie& s : species)
    {
        s.average_fitness *= s.n_indiv;
    }
    for(FitObject& obj : objs)
    {
        Specie &s = species[obj.GetGenes().specie];
        s.average_fitness += obj.GetFitness();
        s.n_indiv++;
    }
    for(Specie& s : species)
    {
        s.average_fitness /= s.n_indiv;
    }
}

void Generation::SortSpecies()
{
    HeapSortDescending(species);
}

//The species table is sorted.
void Generation::UpdateBestSpecie() 
{
    best_specie = species[0];
}
Specie Generation::GetBestSpecie() const
{
    return best_specie;
}

int Generation::GetAllFitness()
{
    int sum = 0;
    for(Specie& s : species)
    {
        sum += s.average_fitness;
    }
    return sum;
}

void Generation::SetBestSpecie(Specie &specie)
{
    best_specie = specie;
}