#include <Graphic/Texture/Texture.hpp>

Texture::Texture():window(nullptr), data(nullptr)
{

}

Texture::Texture(Window *window):window(window), data(nullptr)
{
}

Texture::Texture(Window *window, SDL_Texture* texture):window(window), data(texture)
{
    
}

Texture::Texture(const Texture &other):window(other.window), data(other.data)
{

}

//Ne devrait être appelée que par le TextureManager
void Texture::FreeTexture(){
    //Libère l'espace mémoire pour la texture SDL
    if(this->data)
        SDL_DestroyTexture(this->data);
}

Texture::~Texture()
{
    //Ne libère pas la texture SDL !!!
}

//Si la texture a été initialisée comme copie d'une autre, le pointeur peut avoir été rendu invalide
bool Texture::HasData()
{
    return data != nullptr;
}

Texture& Texture::operator=(const Texture& other)
{
    window = other.window;
    data = other.data;
    return *this;
}

Window * Texture::GetWindow() const 
{
    return window;
}