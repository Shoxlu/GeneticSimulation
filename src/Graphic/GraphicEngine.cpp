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
    CallDrawFuncs();
}


void GraphicEngine::UpdateWindow(Window& window){

    window.Update();
}

GraphicEngine::~GraphicEngine()
{
}

void GraphicEngine::DrawSprite(Window& window, Vec pos, Sprite& sprite)
{
    SpriteManager::DrawSprite(window, pos, sprite);
}

void GraphicEngine::DrawSprite(Window& window, Vec pos, Sprite &sprite,  float x_mult, float y_mult)
{
    sprite.SetDstSize(sprite.dst_size.x * x_mult, sprite.dst_size.y * y_mult);
    SpriteManager::DrawSprite(window, pos, sprite);
    sprite.SetDstSize(sprite.dst_size.x / x_mult, sprite.dst_size.y / y_mult);
}