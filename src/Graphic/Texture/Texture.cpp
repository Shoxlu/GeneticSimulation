#include <Graphic/Texture/Texture.hpp>
#include <Graphic/Texture/Texture.hpp>


Texture::Texture():data(nullptr)
{
}

Texture::Texture(SDL_Texture* texture):data(texture)
{
    
}

void Texture::FreeTexture(){
    //Libère l'espace mémoire pour la texture SDL
    if(this->data)
        SDL_DestroyTexture(this->data);
}

Texture::~Texture()
{
    //Ne libère pas la texture SDL !!!
}
