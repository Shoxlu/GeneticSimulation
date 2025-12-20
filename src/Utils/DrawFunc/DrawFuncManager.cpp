#include <Utils/DrawFunc/DrawFuncManager.hpp>



DrawFuncManager::DrawFuncManager(/* args */)
{
}

DrawFuncManager::~DrawFuncManager()
{
}

void DrawFuncManager::AddDrawFunc(std::function<void()> func, int priority)
{
    DrawFunc f(func, 0);
    size_t id = funcs.Push(f, priority);
    funcs.GetRawData()[id].value.id = id;
}
void DrawFuncManager::DeleteDrawFunc(int id)
{
    funcs.DeleteNodeByIndex(id);
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