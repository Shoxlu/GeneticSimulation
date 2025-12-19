#include <Utils/DrawFunc/DrawFuncManager.hpp>



DrawFuncManager::DrawFuncManager(/* args */)
{
}

DrawFuncManager::~DrawFuncManager()
{
}

void DrawFuncManager::AddDrawFunc(std::function<void()> func, int priority)
{
    funcs.emplace_back(func, priority, funcs.size());
}
void DrawFuncManager::DeleteDrawFunc(int id)
{
    funcs.erase(funcs.begin() + id);
}

void DrawFuncManager::CallDrawFuncs()
{
    for(DrawFunc& func: funcs){
        func();
    }
}