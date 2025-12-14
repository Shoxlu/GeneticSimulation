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
    Texture LoadImage(Window& window,const char *path);
    Texture GetTexture(const char *path);
    void FreeTexture(const char *path);
    void DrawSquareOnTexture(SDL_Texture *texture, Vec pos, Vec rect, RGBA color);
    void ClearTexture(SDL_Texture *texture);
protected:
    static void DrawTexture(Window& window, Vec pos, SDL_Texture *texture);
    static void DrawTexture(Window& window, Vec pos, SDL_Texture *texture, SDL_FRect *src);
    static void DrawTexture(Window& window, SDL_Texture *texture, SDL_FRect *src, SDL_FRect* dest);
    static void DrawTexture(Window& window, SDL_Texture *texture, SDL_FRect *src, SDL_FRect* dst, double angle);
    //void DrawPartTexture(Window& win, SDL_Texture *texture, Vec pos, Vec wh, SDL_FRect *src);

private:
    std::map<std::string, Texture> textures;
};