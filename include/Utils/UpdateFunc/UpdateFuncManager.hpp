#pragma once
#include <Utils/UpdateFunc/UpdateFunc.hpp>
#include <Utils/Heap/Heap.hpp>
#include <vector>
#include <functional>
class UpdateFuncManager
{
private:
    
    PriorityQueue<UpdateFunc> funcs;

public:
    UpdateFuncManager();
    ~UpdateFuncManager();
    void AddUpdateFunc(std::function<void()> f, int priority);
    void DeleteUpdateFunc(int id);
    void CallUpdateFuncs();
};
