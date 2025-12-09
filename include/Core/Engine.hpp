#pragma once
#include <Graphic/Window/Window.hpp>

class Engine: public Window
{
private:
    int dt;
public:
    Engine(int width, int height);
    ~Engine();
    void Start();
    void Terminate();
    void Main();
    void UpdateGraphic();
    void UpdateLogic();
};

