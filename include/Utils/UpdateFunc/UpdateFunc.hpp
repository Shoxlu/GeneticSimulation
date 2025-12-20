#pragma once
#include<functional>

class UpdateFunc
{
private:
    std::function<void()> func;
    int id;
public:
    bool to_execute = true;
    int priority;
    UpdateFunc(std::function<void()> f, int priority, int id);
    ~UpdateFunc();
    template <class T>
    static std::function<void()> GetUpdateFuncFromMethod(T& obj, void (T::*f)())
    {
        return [&obj, f]()
        { (obj.*f)(); };
    };
    void operator()();
};

