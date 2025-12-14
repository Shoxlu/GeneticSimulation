#include <main.h>
#include <Core/Simulation/SimulationManager.hpp>
#include <Tests/Tests.hpp>
#include <assert.h>

void tests();

int main(){
    tests();
    Window mainWindow(1000, 600, 60);
    mainWindow.SetUserFunc(nullptr,nullptr);
    mainWindow.SetTitle("Genetic Simulation");
    log_printf("Fin de l'init.\n");  
    Engine &engine = Engine::Instance();
    SimulationManager simu;
    simu.CreateSimulation(mainWindow, 10, mainWindow.width, mainWindow.height, 1.0);
    while (!mainWindow.WindowClosed())
    {
        engine.UpdateLogic();
        simu.UpdateSimulations();
        simu.DrawSimulations();
        engine.UpdateWindow(mainWindow);
    }
    log_printf("Fin de l'appli ?\n");
    mainWindow.TerminateWindow();
    return 0;
}