#pragma once
#include <SDL3/SDL.h>
#include <Graphic/Window/Window.hpp>
#include <Utils/utils.hpp>




class Drawer{
public:
    static void DrawCircle(Window* window, Vec pos, double radius, RGBA color);

private:
};