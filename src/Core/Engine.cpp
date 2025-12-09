#include <Core/Engine.hpp>
#include <Utils/utils.hpp>

Engine::Engine(int width, int height):GraphicEngine(width, height), dt(1.0)
{
}

Engine::~Engine()
{
}

void Engine::Start(){
    Main();
}

void Engine::UpdateLogic(){

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