#pragma once
#include <Utils/DrawFunc/DrawFunc.hpp>
#include <vector>
#include <functional>
class DrawFuncManager
{
private:
    
    std::vector<DrawFunc> funcs;

public:
    DrawFuncManager();
    ~DrawFuncManager();
    void AddDrawFunc(std::function<void()> f, int priority);
    void DeleteDrawFunc(int id);
    void CallDrawFuncs();
};
