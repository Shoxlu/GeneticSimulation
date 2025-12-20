#pragma once
#include<functional>

class UpdateFunc
{
private:
    std::function<void()> func;

public:
    bool to_execute = true;
    int id;
    UpdateFunc();
    UpdateFunc(std::function<void()> f, int id);
    ~UpdateFunc();
    template <class T>
    static std::function<void()> GetUpdateFuncFromMethod(T& obj, void (T::*f)())
    {
        return [&obj, f]()
        { (obj.*f)(); };
    };
    void operator()();
};

