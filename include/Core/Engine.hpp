#pragma once
#include <Graphic/GraphicEngine.hpp>

class Engine: public GraphicEngine
{
private:
    double dt;
public:
    Engine(int width, int height);
    ~Engine();
    void Start();
    void Terminate();
    void Main();
    void UpdateLogic();
};

