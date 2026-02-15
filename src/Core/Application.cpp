#include <Core/Application.hpp>


Application::Application():
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
    simManager.CreateSimulation(mainWindow, 1, mainWindow.width, mainWindow.height, 0.1666);
    log_printf("Fin de l'init.\n");
    engine.AddUpdateFunc(
        UpdateFunc::GetUpdateFuncFromMethod<SimulationManager>(simManager, SimulationManager::Update),
        0);
    while (!mainWindow.WindowClosed())
    {
        engine.UpdateLogic();
        engine.UserRender();
        engine.UpdateWindow(mainWindow);
    }
    log_printf("Fin de l'appli ?\n");
    mainWindow.TerminateWindow();
   
}
