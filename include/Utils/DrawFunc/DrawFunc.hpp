#pragma once
#include<functional>

class DrawFunc
{
private:
    std::function<void()> func;
    int id;
public:
    bool to_execute = true;
    int priority;
    DrawFunc(std::function<void()> f, int priority, int id);
    ~DrawFunc();
    template <class T>
    static std::function<void()> GetDrawFuncFromMethod(T& obj, void (T::*f)())
    {
        return [&obj, f]()
        { (obj.*f)(); };
    };
    void operator()();
};

