#pragma once
#include <map>
#include <SDL3/SDL.h>
#include <string>
#include <Graphic/Window/Window.hpp>
#include <Graphic/Texture/Texture.hpp>
#include <Utils/utils.hpp>

class TextureManager{
public:
    TextureManager();
    ~TextureManager();
    //Charge une image bmp et la renvoie
    Texture LoadImage(Window& win,const char *path);
    Texture GetImage(const char *path);
    void DrawSquareOnTexture(SDL_Texture *texture, Vec pos, Vec rect, RGBA color);
    void ClearTexture(SDL_Texture *texture);
    void DrawTexture(Window& win, Vec pos, SDL_Texture *texture);
    void DrawTexture(Window& win, Vec pos, SDL_Texture *texture, SDL_FRect *src);
    void DrawTexture(Window &win, Vec pos, SDL_Texture *texture, float x_mult, float y_mult);
    void DrawTexture(Window &win, Vec pos, SDL_Texture *texture, SDL_FRect *src, float x_mult, float y_mult);
    //void DrawPartTexture(Window& win, SDL_Texture *texture, Vec pos, Vec wh, SDL_FRect *src);

private:
    std::map<std::string, Texture> textures;
};