#include <Utils/UpdateFunc/UpdateFuncManager.hpp>



UpdateFuncManager::UpdateFuncManager(/* args */)
{
}

UpdateFuncManager::~UpdateFuncManager()
{
}

void UpdateFuncManager::AddUpdateFunc(std::function<void()> func, int priority)
{
    funcs.emplace_back(func, priority, funcs.size());
}
void UpdateFuncManager::DeleteUpdateFunc(int id)
{
    funcs.erase(funcs.begin() + id);
}

void UpdateFuncManager::CallUpdateFuncs()
{
    for(UpdateFunc& func: funcs){
        func();
    }
}