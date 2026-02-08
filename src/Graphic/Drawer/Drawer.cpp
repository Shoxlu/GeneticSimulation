#include <Graphic/Drawer/Drawer.hpp>
#include <math.h>


void Drawer::DrawCircle(Window* window, Vec pos, double radius, RGBA color)
{
    //Partially AI generated.
    const int segments = 32;
    double angleStep = 2.0 * M_PI / segments;
    SDL_Renderer *renderer = window->GetRenderer();
    RGBA old_color;
    SDL_GetRenderDrawColor(renderer,
        &old_color.rgba.components.r,
        &old_color.rgba.components.g,
        &old_color.rgba.components.b,
        &old_color.rgba.components.a);
    SDL_SetRenderDrawColor(renderer,
        color.rgba.components.r,
        color.rgba.components.g,
        color.rgba.components.b, 
        color.rgba.components.a);
    for (int i = 0; i < segments; ++i) {
        double angle1 = i * angleStep;
        double angle2 = (i + 1) * angleStep;
        
        int x1 = static_cast<int>(pos.x + radius * cos(angle1));
        int y1 = static_cast<int>(pos.y + radius * sin(angle1));
        int x2 = static_cast<int>(pos.x + radius * cos(angle2));
        int y2 = static_cast<int>(pos.y + radius * sin(angle2));
        
        SDL_RenderLine(renderer, static_cast<float>(x1), static_cast<float>(y1),
                       static_cast<float>(x2), static_cast<float>(y2));
    }
    SDL_SetRenderDrawColor(renderer,
    old_color.rgba.components.r,
    old_color.rgba.components.g,
    old_color.rgba.components.b, 
    old_color.rgba.components.a);
}