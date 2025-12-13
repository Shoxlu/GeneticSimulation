#include <Core/Engine.hpp>
#include <Utils/utils.hpp>

Engine::Engine(int width, int height):GraphicEngine(width, height), dt(1.0)
{
}

Engine::Engine():GraphicEngine(0, 0), dt(1.0)
{
}

Engine::~Engine()
{
}

void Engine::Start(){

}

void Engine::Main(){
    
}

void Engine::Terminate(){

}