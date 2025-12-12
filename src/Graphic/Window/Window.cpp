#include <stdlib.h>
#include <stdio.h>
#include <Graphic/Window/Window.hpp>
#include <Utils/Error/error.hpp>

Window::Window(int width, int height){
    InitWindow(width, height);
}

//Initialise la fenêtre SDL
int Window::InitWindow(int width, int height){
    //Initialise SDL pour la video et les events
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        log_printf("L'initialisation de SDL a échoué, problème de librairie ?\n");
        return -1;
    }
    this->window_height = height;
    this->window_width = width;
    //Création de la fenêtre 
    this->gSDLWindow = SDL_CreateWindow("SDL3 window", width, height, 0);
    //Création du Renderer (?)
    this->gSDLRenderer = SDL_CreateRenderer(this->gSDLWindow, NULL);
    this->gDone = false;
    SDL_SetRenderDrawColor(this->gSDLRenderer, 30, 30, 30, 255);
    if (!this->gSDLWindow || !this->gSDLRenderer)
    {
        log_printf("Echec de l'initialisation de Window\n");
        return -1;
    }
        
    return 0;
}

void Window::SetUserFunc( void(*render_func)(), void (*user_events)()){
    log_printf("ATTENTION LES FONCTIONS DE RENDUS PERSONNALISEES NE SONT PLUS SUPPORTEES\n");
    if(render_func == NULL){
        log_printf("Pas de fonction de rendu ? Une fonction de rendu par défaut sera utilisé\n");
    }
    if(user_events == NULL){
        log_printf("Pas de fonction d'events ? Les events par défaut seront pris en compte\n");
    }
    //this->render_function = render_func;
    this->user_events = user_events;
}

void Window::SetTitle(std::string new_title){
    SDL_SetWindowTitle(this->gSDLWindow, new_title.data());
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

void Window::CloseWindow(){
    this->gDone = true;
}

SDL_Renderer* Window::GetRenderer(){
    return this->gSDLRenderer;
}

void Window::TerminateWindow(){
    log_printf("Fin de l'appli!\n");
    //Libère toutes les ressources
    SDL_DestroyRenderer(this->gSDLRenderer);
    SDL_DestroyWindow(this->gSDLWindow);
    SDL_Quit();
}

bool Window::WindowClosed(){
    return this->gDone;
}