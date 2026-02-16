#include <Core/Engine.hpp>
#include <Utils/utils.hpp>

Engine::Engine()
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

void DeleteDrawFunc(int id)
{
    Engine::Instance().DeleteDrawFunc(id);
}