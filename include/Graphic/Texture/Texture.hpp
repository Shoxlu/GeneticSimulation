#pragma once
#include <SDL3/SDL.h>


//Petit encapsuleur d'un pointeur vers une texture, ne le libère pas quand l'objet disparait !
class Texture
{
private:

public:
    SDL_Texture *data;
    Texture();
    Texture(SDL_Texture *texture);
    void FreeTexture();
    ~Texture();
};
