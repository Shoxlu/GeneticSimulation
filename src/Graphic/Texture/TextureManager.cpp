#include <Graphic/Texture/TextureManager.hpp>
#include <Utils/utils.hpp>


TextureManager::TextureManager(){

}

TextureManager::~TextureManager(){
    for (auto& [key, value] : textures) {
        value.FreeTexture();
    }
}

Texture TextureManager::GetImage(const char* path){
    Texture texture = textures[path];
    return texture;
}

Texture TextureManager::LoadImage(Window& win, const char* path){
    Texture text = GetImage(path);
    if(text.data){
        log_printf("La texture existait déjà, elle est réutilisée.\n");
        return text;
    }
    //Charge un bmp
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (!surface) {
        log_printf("Erreur SDL_LoadBMP: %s\n", SDL_GetError());
    }
    // Convertit en texture pour l’affichage
    SDL_Renderer *renderer = win.GetRenderer();
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface); // plus besoin de la surface
    if (!texture) {
        log_printf("Erreur SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
    }
    textures[path] = Texture(texture);
    log_printf("La texture %s a été chargée avec succès\n", path);
    return textures[path];
}
