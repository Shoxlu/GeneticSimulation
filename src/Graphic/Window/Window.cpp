#include <stdlib.h>
#include <stdio.h>
#include <Graphic/Window/Window.h>
#include <Utils/Error/error.h>

/*
Written by MILCENDEAU Timothée 2025
Inspired from SOL's tutorial on SDL
*/


Window::Window(int height, int width){
    InitWindow(height, width);
}

//Initialise la fenêtre SDL
int Window::InitWindow(int height, int width){
    //Initialise SDL pour la video et les events
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        log_printf("L'initialisation de SDL a échoué, problème de librairie ?\n");
        return -1;
    }
    this->height = height;
    this->width = width;
    //Matrice linéarisée des pixels
    this->gFrameBuffer.resize(height * width);
    //Création de la fenêtre 
    this->gSDLWindow = SDL_CreateWindow("SDL3 window", width, height, 0);
    //Création du Renderer (?)
    this->gSDLRenderer = SDL_CreateRenderer(this->gSDLWindow, NULL);
    //Création d'une texture
    this->gSDLTexture = SDL_CreateTexture(this->gSDLRenderer,
        SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING,
        width, height);
    this->gDone = false;
    SDL_SetRenderDrawColor(this->gSDLRenderer, 30, 30, 30, 255);
    if (!this->gSDLWindow || !this->gSDLRenderer || !this->gSDLTexture)
    {
        log_printf("Echec de l'initialisation de Window\n");
        return -1;
    }
        
    return 0;
}

void Window::SetUserFunc( void(*render_func)(), void (*user_events)()){
    if(render_func == NULL){
        log_printf("Pas de fonction de rendu ? Une fonction de rendu par défaut sera utilisé\n");
    }
    if(user_events == NULL){
        log_printf("Pas de fonction d'events ? Les events par défaut seront pris en compte\n");
    }
    this->render_function = render_func;
    this->user_events = user_events;
}

void Window::SetTitle(std::string new_title){
    SDL_SetWindowTitle(this->gSDLWindow, new_title.data());
}

// SDL_Texture** load_textures(){
//     SDL_Texture **tab = malloc(sizeof(SDL_Texture *) * N_TEXTURES);
//     tab[pawn] = load_image("./imgs/pawn.bmp");
//     tab[rook] = load_image("./imgs/rook.bmp");
//     tab[queen] = load_image("./imgs/queen.bmp");
//     tab[king] = load_image("./imgs/king.bmp");
//     tab[knight] = load_image("./imgs/knight.bmp");
//     tab[bishop] = load_image("./imgs/bishop.bmp");
//     return tab;
// }

void Window::DestroyTextures(SDL_Texture** tab){
    for (int i = 0; i < N_TEXTURES; i++){
        SDL_DestroyTexture(tab[0]);
    }
    free(tab);
}


bool Window::ManageEvents(){
    SDL_Event e;
    //Récupère tous les évènements qui se sont produits et en fait quelque chose
    while (SDL_PollEvent(&e))
    {
        if(this->user_events != nullptr){
            this->user_events();
        }
        if (e.type == SDL_EVENT_QUIT)
        {
            return false;
        }
        if (e.key.key == SDLK_ESCAPE)
        {
            return false;
        }
    }
    return true;
}

//Inutilisé
// void Window::draw(){
//     char* pix;
//     int pitch;
//     SDL_LockTexture(this->gSDLTexture, NULL, (void**)&pix, &pitch);
//     //Fill the texture with the frameBuffer (the texture is the entire screen)
//     for (int i = 0, sp = 0, dp = 0; i < this->height; i++, dp += this->width, sp += pitch){
//         memcpy(&pix[sp], &this->gFrameBuffer[dp], this->width * 4);
//     }
//     SDL_UnlockTexture(this->gSDLTexture);  
// }

// void clear_frame_buffer(){
//     for (int i = 0, c = 0; i < this->height; i++)
//     {
//         for (int j = 0; j < this->width; j++, c++)
//         {
//             this->gFrameBuffer[c] = 0;
//         }
//     }
// }
void default_render() {
}

void Window::Render(){
    SDL_Delay(16);
    SDL_RenderClear(this->gSDLRenderer);
    if(this->render_function == NULL){
        this->render_function = default_render;
    }
    this->render_function();
    SDL_RenderPresent(this->gSDLRenderer);
}

void Window::CloseWindow(){
    this->gDone = true;
}

void Window::UpdateWindow() {

    if (!ManageEvents())
    {
        CloseWindow();
    }else{
        Render();
    }
}


SDL_Renderer* Window::GetRenderer(){
    return this->gSDLRenderer;
}

void Window::TermintateWindow(){
    log_printf("Fin de l'appli!\n");
    //Libère toutes les ressources
    SDL_DestroyTexture(this->gSDLTexture);
    SDL_DestroyRenderer(this->gSDLRenderer);
    SDL_DestroyWindow(this->gSDLWindow);
    SDL_Quit();
}

bool Window::WindowClosed(){
    return this->gDone;
}