#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <string>

class Window{
public:
    Window(int width, int height);
    int InitWindow(int w, int h);
    void TerminateWindow();
    void SetTitle(std::string new_title);
    static SDL_Renderer *GetRenderer();
    bool WindowClosed();
    void SetUserFunc(void (*render_func)(), void (*user_events)());
    bool ManageEvents();
    void Render();
    void CloseWindow();

private:
    std::string title;
    //Je ne sais pas s'il y a un meilleur moyen que de rendre ça global (statique ici mais c'est pareil...)
    static SDL_Window *gSDLWindow;
    static SDL_Renderer *gSDLRenderer;
    void (*render_function)();
    void (*user_events)();
    bool gDone;
    int window_width;
    int window_height;
};
