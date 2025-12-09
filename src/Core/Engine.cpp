#include <Core/Engine.hpp>
#include <Utils/utils.hpp>

Engine::Engine(int width, int height):Window(width, height), dt(1)
{
    SetUserFunc(nullptr, nullptr);
    SetTitle("Genetic Simulation");
    log_printf("Fin de l'init.\n");
}

Engine::~Engine()
{
}

void Engine::Start(){
    Main();
}

void Engine::UpdateLogic(){

}

void Engine::UpdateGraphic(){
    UpdateWindow();
}

void Engine::Main(){
    while (!WindowClosed())
    {
        UpdateLogic();

        UpdateGraphic();
    }
    log_printf("Fin de l'appli ?\n");
    TermintateWindow();
}

void Engine::Terminate(){

}