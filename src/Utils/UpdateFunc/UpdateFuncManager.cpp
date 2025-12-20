#include <Utils/UpdateFunc/UpdateFuncManager.hpp>



UpdateFuncManager::UpdateFuncManager(/* args */)
{
}

UpdateFuncManager::~UpdateFuncManager()
{
}

void UpdateFuncManager::AddUpdateFunc(std::function<void()> func, int priority)
{
    UpdateFunc f(func, 0);
    size_t id = funcs.Push(f, priority);
    funcs.GetRawData()[id].value.id = id;
}
void UpdateFuncManager::DeleteUpdateFunc(int id)
{
    funcs.DeleteNodeByIndex(id);
}

void UpdateFuncManager::CallUpdateFuncs()
{
    OrderedPair<UpdateFunc> p;
    PriorityQueue<UpdateFunc> copy_funcs = funcs;
    while(!copy_funcs.IsEmpty())
    {
        p = copy_funcs.Pop();
        p.value();
    }
}