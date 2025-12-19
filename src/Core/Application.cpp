#include <Core/Application.hpp>


Application::Application(/* args */):
engine(Engine::Instance())
{
}

Application::~Application()
{
}

void Application::Run()
{
    Window mainWindow(1000, 600, 60);
    mainWindow.SetUserFunc(nullptr,nullptr);
    mainWindow.SetTitle("Genetic Simulation");
    simManager.CreateSimulation(mainWindow, 10, mainWindow.width, mainWindow.height, 1.0);
    log_printf("Fin de l'init.\n");  
    while (!mainWindow.WindowClosed())
    {
        engine.UpdateLogic();
        simManager.UpdateSimulations();
        simManager.DrawSimulations();
        engine.UpdateWindow(mainWindow);
    }
    log_printf("Fin de l'appli ?\n");
    mainWindow.TerminateWindow();
   
}
