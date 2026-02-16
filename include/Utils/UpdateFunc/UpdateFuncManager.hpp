#pragma once
#include <Utils/UpdateFunc/UpdateFunc.hpp>
#include <Utils/Heap/Heap.hpp>
#include <vector>
#include <functional>
class UpdateFuncManager
{
private:
    
    PriorityQueue<UpdateFunc> funcs;
    std::vector<int> free_ids;
    int last_id = 0;
public:
    UpdateFuncManager();
    ~UpdateFuncManager();
    size_t AddUpdateFunc(std::function<void()> f, int priority);
    void DeleteUpdateFunc(int id);
    void CallUpdateFuncs();
};
