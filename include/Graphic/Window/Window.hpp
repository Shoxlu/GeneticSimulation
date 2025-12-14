#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <string>

class Window{
public:
    Window(int width, int height, int framerate);
    int InitWindow(int w, int h);
    void TerminateWindow();
    void SetTitle(std::string new_title);
    SDL_Renderer *GetRenderer();
    bool WindowClosed();
    void SetUserFunc(void (*render_func)(), void (*user_events)());
    bool ManageEvents();
    void Render();
    void CloseWindow();
    void Update();
    int framerate;
    int width;
    int height;
private:
    std::string title;
    SDL_Window *gSDLWindow;
    SDL_Renderer *gSDLRenderer;
    void (*render_function)();
    void (*user_events)();
    bool gDone;


};
