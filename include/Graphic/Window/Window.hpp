#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <string>

class Window{
public:
    Window(int height, int width);
    int InitWindow(int h, int w);
    void TermintateWindow();
    void SetTitle(std::string new_title);
    SDL_Renderer *GetRenderer();
    bool WindowClosed();
    void SetUserFunc(void (*render_func)(), void (*user_events)());
    bool ManageEvents();
    void Render();
    void CloseWindow();

private:
    std::string title;
    SDL_Window *gSDLWindow;
    SDL_Renderer *gSDLRenderer;
    void (*render_function)();
    void (*user_events)();
    bool gDone;
    int width;
    int height;
};