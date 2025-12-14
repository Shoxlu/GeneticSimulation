#pragma once
#include <SDL3/SDL.h>
#include <Graphic/Window/Window.hpp>


//Petit encapsuleur d'un pointeur vers une texture, ne le libère pas quand l'objet disparait !
class Texture
{
private:
protected:
    //Une texture est TOUJOURS liée à un fenêtre SDL, donc au lieu de laisser le dev gérer les bonnes fenêtres, on la stocke
    Window *window;
public:
    SDL_Texture *data;
    Texture();
    Texture(const Texture &other);
    Texture(Window *window);
    Texture(Window *window, SDL_Texture *texture);
    ~Texture();
    void FreeTexture();
    bool HasData();
    Texture &operator=(const Texture &other);
};
