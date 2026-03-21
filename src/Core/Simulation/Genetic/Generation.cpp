#include <Core/Simulation/Genetic/Generation.hpp>
#include <Utils/utils.hpp>

#define DIFF_SPECIE 2.0

Specie::Specie() 
{

}
Specie::~Specie() 
{

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
    UpdateSpecies(new_objs);
    return new_objs;
}

std::vector<FitObject> Generation::NewGeneration(std::vector<FitObject>& old_generation) 
{
    std::vector<FitObject> new_objs;
    size_t size = old_generation.size();
    int all_fitness = GetAllFitness();
    printf("All fitness %d\n", all_fitness);
    size_t count = 0;
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
    UpdateSpecies(new_objs);
    return new_objs;
}

std::vector<FitObject> Generation::NewGenerationSimple(std::vector<FitObject>& old_generation) 
{
    std::vector<FitObject> new_objs;
    size_t size = old_generation.size();
    int all_fitness = GetAllFitness();
    HeapSortDescending(old_generation);
    size_t count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(i < size/3)
        {
            
        }
        else if (i < size/3+size/3)
        {

        }
        else
        {
            
        }
       
        if(count >= size)
            break;
    }
    UpdateSpecies(new_objs);
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
    GeneticInfo b = species[specie].base_genes;
    b.Mutate(1);
    return b;
}

//The new individual gets half the specs of the first and second specie
GeneticInfo Generation::CreateNewIndividual(size_t specie1, size_t specie2) 
{
    return CreateNewIndividual(species[specie1].base_genes, species[specie2].base_genes);
}

//The new individual gets half the specs of the first and second parent
GeneticInfo Generation::CreateNewIndividual(GeneticInfo& obj1, GeneticInfo& obj2) 
{
    GeneticInfo new_genes;
    new_genes.speed = obj1.speed;
    new_genes.size = obj1.size;
    // RGBA new_color = obj1.color;

    if(Random::RandBool())
    {
        new_genes.speed = obj2.speed;
    }
    if(Random::RandBool())
    {
        new_genes.size = obj2.size;
    }
    // if(Random::RandBool())
    // {
    //     new_color = obj2.color;
    // }
    new_genes.Mutate(1);
    return new_genes;
}

void Generation::UpdateSpecies(std::vector<FitObject>& objs) 
{
    for (FitObject& obj : objs)
    {
        GeneticInfo genes = obj.genes;
        Specie new_specie = FindNewSpecie(genes);
        if(new_specie.id != genes.specie && last_specie_id != -1)
        {
            species[genes.specie].n_indiv--;
        }
    }
    //Supprimer les species vide.
    
}

double Generation::SpecieScore(Specie& specie, GeneticInfo& genes)
{
    //Creates a virtual vector (mathematic one) with diff of each gene and takes the norm of it as the score
    double size_diff = specie.base_genes.size - genes.size;
    double speed_diff = specie.base_genes.speed - genes.speed;
    //RGBA color_diff = specie.base_genes.color - genes.color;
    return sqrt(size_diff*size_diff+speed_diff*speed_diff);
}

Specie Generation::FindNewSpecie(GeneticInfo genes) 
{
    //To be completed
    Specie new_specie;

    if(last_specie_id >=0)
    {
        size_t specie_min = 0;
        double score_min = SpecieScore(species[0], genes);;
        for(size_t i = 1; i < species.size();i++)
        {
            Specie &specie = species[i];
            double new_score = SpecieScore(specie, genes);
            if(new_score < score_min)
            {
                score_min = new_score;
                specie_min = i;
            }
        }
        printf("Score max %f\n", score_min);
        if(score_min < DIFF_SPECIE)
        {
            return species[specie_min];
        }
    }
    new_specie.base_genes = genes;
    new_specie.id = ++last_specie_id;
    new_specie.n_indiv = 1;
    printf("New specie !\n");
    species.emplace_back(new_specie);
    return new_specie;
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
        Specie &s = species[obj.genes.specie];
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
    if(species.size() > 0)
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