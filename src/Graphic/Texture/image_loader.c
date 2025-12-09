#include <Graphic/Texture/image_loader.hpp>
#include <Utils/utils.hpp>

//Faut-il vraiment faire une classe pour ça ?

SDL_Texture* load_image(char* path){
    //Charge un bmp
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (!surface) {
        log_printf("Erreur SDL_LoadBMP: %s\n", SDL_GetError());
    }
    // Convertit en texture pour l’affichage
    SDL_Renderer *renderer = get_renderer();
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface); // plus besoin de la surface
    if (!texture) {
        log_printf("Erreur SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
    }
    return texture;
}
