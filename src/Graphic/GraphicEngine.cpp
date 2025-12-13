#include <Graphic/GraphicEngine.hpp>
#include <Utils/utils.hpp>



GraphicEngine::GraphicEngine(int width, int height):Window(width, height)
{
    SetUserFunc(nullptr,nullptr);
    SetTitle("Genetic Simulation");
    log_printf("Fin de l'init.\n");
}

Texture GraphicEngine::GetTexture(const char* path){
    return LoadImage(GetRenderer(), path);
}

Sprite GraphicEngine::CreateSprite(const char* path){
    return SpriteManager::CreateSprite(GetRenderer(), path);
}


void GraphicEngine::UserRender(){
    Texture text = GetTexture("../img/pawn.bmp");
    Vec pos(200, 300);
    TextureManager::DrawTexture(GetRenderer(), pos, text.data);
}

void GraphicEngine::UpdateGraphic(){
    
    if (!ManageEvents())
    {
        CloseWindow();
    }else{
        SDL_Delay(16);
        UserRender();
        SDL_RenderPresent(GetRenderer());
        SDL_RenderClear(GetRenderer());
    }
}

GraphicEngine::~GraphicEngine()
{
}

void GraphicEngine::DrawSprite(Vec pos, Sprite& sprite)
{
    SpriteManager::DrawSprite(Window::GetRenderer(), pos, sprite, 1.0, 1.0);
}

void GraphicEngine::DrawSprite(Vec pos, Sprite &sprite,  float x_mult, float y_mult)
{
    SpriteManager::DrawSprite(Window::GetRenderer(), pos, sprite, x_mult, y_mult);
}