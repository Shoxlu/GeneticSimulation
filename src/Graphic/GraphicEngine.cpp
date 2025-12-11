#include <Graphic/GraphicEngine.hpp>
#include <Utils/utils.hpp>



GraphicEngine::GraphicEngine(int width, int height):Window(width, height)
{
    SetUserFunc(nullptr,nullptr);
    SetTitle("Genetic Simulation");
    log_printf("Fin de l'init.\n");
}

Texture GraphicEngine::GetTexture(const char* path){
    return textureManager.LoadImage(*this, path);
}


void GraphicEngine::UserRender(){
    Texture text = GetTexture("../img/pawn.bmp");
    Vec pos(200, 300);
    textureManager.DrawTexture(*this, pos, text.data);
}

void GraphicEngine::UpdateGraphic(){
    
    if (!ManageEvents())
    {
        CloseWindow();
    }else{
        SDL_Delay(16);
        SDL_RenderClear(GetRenderer());
        UserRender();
        SDL_RenderPresent(GetRenderer());
    }
}

GraphicEngine::~GraphicEngine()
{
}
