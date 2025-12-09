#include <Graphic/Texture/TextureManager.hpp>
#include <Graphic/Texture/TextureManager.hpp>
#include <stdlib.h>

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


void TextureManager::DrawSquareOnTexture(SDL_Texture* texture, Vec pos, Vec rect, RGBA color)
{

    char* pix;
    int pitch;
    int w, h;
    float wf, hf;
    SDL_GetTextureSize(texture, &wf, &hf);
    SDL_Rect rect_sdl;
    rect_sdl.x = (float)pos.x;
    rect_sdl.y = (float)pos.y;
    rect_sdl.w = (float)rect.x;
    rect_sdl.h = (float)rect.y;
    SDL_LockTexture(texture, &rect_sdl, (void**)&pix, &pitch);
    w = pitch / 4;
    h = hf;
    pos.x = std::min(std::max(0, rect_sdl.x),w);
    pos.y =  std::min(std::max(0, rect_sdl.y),h);
    for (int i = 0; i < std::min(rect_sdl.h,h); i++) 
    {
       
        for (int j = 0; j < std::min(rect_sdl.w, w); j++)
        {
            ((int*)pix)[i*w+j] = color.rgba.rgba;
        }
    }
    SDL_UnlockTexture(texture);
    
}

void TextureManager::ClearTexture(SDL_Texture* texture)
{
    char* pix;
    int pitch;
    float w, h;
    SDL_GetTextureSize(texture, &w, &h);
    SDL_LockTexture(texture, NULL, (void**)&pix, &pitch);
    for (int i = 0; i < w; i++) 
    {
        for (int j = 0; j <h; j++)
        {
            RGBA color = {0, 0, 0, 255};
            ((int*)pix)[i+(int)h*j]= color.rgba.rgba;
        }
    }
    SDL_UnlockTexture(texture);
}

void TextureManager::DrawTexture(Window& win, Vec pos, SDL_Texture* texture, SDL_FRect* rect)
{
    float w, h;
    SDL_GetTextureSize(texture, &w, &h);
    SDL_FRect dst = {pos.x, pos.y, w, h};
    SDL_RenderTexture(win.GetRenderer(), texture, rect, &dst);
}

void TextureManager::DrawPartTexture(Window& win,SDL_Texture* texture, Vec pos, Vec wh, SDL_FRect* src)
{
    SDL_FRect dst = {pos.x, pos.y, wh.x, wh.y};
    SDL_RenderTexture(win.GetRenderer(), texture, src, &dst);

}