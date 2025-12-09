#include <Graphic/GraphicEngine.hpp>
#include <Utils/utils.hpp>



GraphicEngine::GraphicEngine(int width, int height):Window(width, height)
{
    SetUserFunc(GraphicEngine::UserRender,nullptr);
    SetTitle("Genetic Simulation");
    Texture test = GetTexture("../img/pawn.bmp");
    Texture test2 = GetTexture("../img/pawn.bmp");
    log_printf("Fin de l'init.\n");
}

Texture GraphicEngine::GetTexture(const char* path){
    return textureManager.LoadImage(*this, path);
}


void GraphicEngine::UserRender(){
    
}

void GraphicEngine::UpdateGraphic(){
    
    if (!ManageEvents())
    {
        CloseWindow();
    }else{
        Render();
    }
}

GraphicEngine::~GraphicEngine()
{
}
