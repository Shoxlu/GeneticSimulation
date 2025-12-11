#include <Logic/Simulation/Simulation.hpp>

Simulation::Simulation(){

}
Simulation::Simulation(int n_obj, double dt, double width, double height):
World(width, height), dt(dt)
{
    objects.resize(n_obj);
}

Simulation::~Simulation(){

}
    
void Simulation::Update(){
    for(Object& obj: objects){
        obj.UpdatePos(dt);
        obj.ClampToEdge(0, 0, width, height);
    }
}