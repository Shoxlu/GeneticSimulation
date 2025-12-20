#pragma once
#include <Utils/DrawFunc/DrawFunc.hpp>
#include <vector>
#include <functional>

//C'est une copie de UpdateFuncManager, je sais pas si c'est utile de séparer. 
//J'imaginais qu'il y aurait des différences mais pas tant.
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
