#pragma once
#include <Graphic/GraphicEngine.hpp>
#include <Logic/LogicEngine.hpp>

class Engine: public GraphicEngine, public LogicEngine
{
private:
    double dt;
public:
    Engine();
    Engine(int width, int height);
    ~Engine();
    void Start();
    void Terminate();
    void Main();
};

