#pragma once
#include <Utils/UpdateFunc/UpdateFunc.hpp>
#include <vector>
#include <functional>
class UpdateFuncManager
{
private:
    
    std::vector<UpdateFunc> funcs;

public:
    UpdateFuncManager();
    ~UpdateFuncManager();
    void AddUpdateFunc(std::function<void()> f, int priority);
    void DeleteUpdateFunc(int id);
    void CallUpdateFuncs();
};
