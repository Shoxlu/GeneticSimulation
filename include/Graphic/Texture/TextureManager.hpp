#pragma once
#include <map>
#include <SDL3/SDL.h>
#include <string>
#include <Graphic/Window/Window.hpp>
#include <Graphic/Texture/Texture.hpp>

class TextureManager{
public:
    TextureManager();
    ~TextureManager();
    //Charge une image bmp et la renvoie
    Texture LoadImage(Window& win,const char *path);
    Texture GetImage(const char *path);
private:
    std::map<std::string, Texture> textures;
};