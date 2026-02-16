#include <Utils/UpdateFunc/UpdateFuncManager.hpp>

UpdateFuncManager::UpdateFuncManager(/* args */) : free_ids(0)
{
}

UpdateFuncManager::~UpdateFuncManager()
{
}

size_t UpdateFuncManager::AddUpdateFunc(std::function<void()> func, int priority)
{
    UpdateFunc f(func, 0);
    size_t index_in_heap = funcs.Push(f, priority);
    size_t id = 0;
    size_t size = free_ids.size();
    if(size == 0)
    {
        id = last_id;
        last_id++;
    }else
    {
        id = free_ids[size - 1];
        free_ids.pop_back();
    }
    funcs.GetRawData()[index_in_heap].value.id = id;
    return id;
}
void UpdateFuncManager::DeleteUpdateFunc(int id)
{
    for (size_t i = 0; i < funcs.size(); i++)
    {
        if(id == funcs[i].value.id)
        {
            funcs.DeleteNodeByIndex(i);
            free_ids.emplace_back(id);
        }
    }
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