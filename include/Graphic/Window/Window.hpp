#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <string>
/*
Written by MILCENDEAU Timothée 2025
Inspired from SOL's tutorial on SDL
*/

#define N_TEXTURES 6

class Window{
public:
    Window(int height, int width);
    int InitWindow(int h, int w);
    void TermintateWindow();
    void UpdateWindow();
    void SetTitle(std::string new_title);
    SDL_Renderer *GetRenderer();
    // SDL_Texture **load_textures();
    void DestroyTextures(SDL_Texture **tab);
    bool WindowClosed();
    void SetUserFunc(void (*render_func)(), void (*user_events)());
    bool ManageEvents();
    void Render();
    void CloseWindow();

private:
    std::string title;
    std::vector<int> gFrameBuffer;
    SDL_Window *gSDLWindow;
    SDL_Renderer *gSDLRenderer;
    SDL_Texture *gSDLTexture;
    void (*render_function)();
    void (*user_events)();
    bool gDone;
    int width;
    int height;
};