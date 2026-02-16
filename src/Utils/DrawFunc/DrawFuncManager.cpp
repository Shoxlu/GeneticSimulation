#include <Utils/DrawFunc/DrawFuncManager.hpp>



DrawFuncManager::DrawFuncManager(/* args */): free_ids(0)
{
}

DrawFuncManager::~DrawFuncManager()
{
}

int DrawFuncManager::AddDrawFunc(std::function<void()> func, int priority)
{
    DrawFunc f(func, 0);
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
void DrawFuncManager::DeleteDrawFunc(int id)
{
    //Bad, but enough
    for (size_t i = 0; i < funcs.size(); i++)
    {
        if(id == funcs[i].value.id)
        {
            funcs.DeleteNodeByIndex(i);
            free_ids.emplace_back(id);
        }
    }
        
}

void DrawFuncManager::CallDrawFuncs()
{
    OrderedPair<DrawFunc> p;
    PriorityQueue<DrawFunc> copy_funcs = funcs;
    while(!copy_funcs.IsEmpty())
    {
        p = copy_funcs.Pop();
        p.value();
    }
}