#include <Graphic/GraphicEngine.hpp>
#include <Utils/utils.hpp>



GraphicEngine::GraphicEngine()
{
    
}

Texture GraphicEngine::GetTexture(Window& window, const char* path){
    return LoadImage(window, path);
}

Sprite GraphicEngine::CreateSprite(Window& window, const char* path){
    return SpriteManager::CreateSprite(window, path);
}


void GraphicEngine::UserRender(){
    // Texture text = GetTexture("../img/pawn.bmp");
    // Vec pos(200, 300);
    // TextureManager::DrawTexture(GetRenderer(), pos, text.data);
}


void GraphicEngine::UpdateWindow(Window& window){

    window.Update();
}

GraphicEngine::~GraphicEngine()
{
}

void GraphicEngine::DrawSprite(Window& window, Vec pos, Sprite& sprite)
{
    SpriteManager::DrawSprite(window, pos, sprite, 1.0, 1.0);
}

void GraphicEngine::DrawSprite(Window& window, Vec pos, Sprite &sprite,  float x_mult, float y_mult)
{
    SpriteManager::DrawSprite(window, pos, sprite, x_mult, y_mult);
}