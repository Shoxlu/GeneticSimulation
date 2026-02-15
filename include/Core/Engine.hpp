#pragma once
#include <Graphic/GraphicEngine.hpp>
#include <Logic/LogicEngine.hpp>

class Engine: public GraphicEngine, public LogicEngine
{
private:
    Engine();
public:
    static Engine& Instance(){
        static Engine instance;
        //log_printf("engine: %p\n", &instance);
        return instance;
    }
    ~Engine();
    void Start();
    void Terminate();
    void Main();
};

template<typename T>
void AddToDrawQueue(T& obj)
{
    obj.draw_id = Engine::Instance().AddDrawFunc(
        DrawFunc::GetDrawFuncFromMethod<T>(
            obj,
            T::Draw
        ), 0);
}

void DeleteDrawFunc(int id);
