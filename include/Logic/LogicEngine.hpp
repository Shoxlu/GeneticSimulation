#pragma once
#include <Utils/UpdateFunc/UpdateFuncManager.hpp>

//Pour les trucs de logiques
class LogicEngine: public UpdateFuncManager
{
private:
    
public:
    void UpdateLogic();
    LogicEngine();
    ~LogicEngine();
};

