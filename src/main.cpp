#include <main.h>
#include <Core/Simulation/SimulationManager.hpp>
#include <Tests/Tests.hpp>
#include <assert.h>


int main(){
    tests();
    
    Engine &engine = Engine::Instance();
    SimulationManager simu;
    Window mainWindow(1000, 600, 60);
    mainWindow.SetUserFunc(nullptr,nullptr);
    mainWindow.SetTitle("Genetic Simulation");
    simu.CreateSimulation(mainWindow, 10, mainWindow.width, mainWindow.height, 1.0);
    log_printf("Fin de l'init.\n");  
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