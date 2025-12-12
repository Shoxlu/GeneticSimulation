#include <main.h>
#include <Core/Simulation/Simulation.hpp>
#include <Tests/Tests.hpp>
#include <assert.h>

void tests();

int main(){
    tests();
    Simulation simu(10, 1, 1000, 600);
    simu.Start();
    simu.Terminate();
    return 0;
}