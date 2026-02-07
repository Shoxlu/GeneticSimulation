#pragma once
#include<functional>

class DrawFunc
{
private:
    std::function<void()> func;
public:
    bool to_execute = true;
    int id;
    DrawFunc(std::function<void()> f, int id);
    DrawFunc();
    ~DrawFunc();
    template <class T>
    static std::function<void()> GetDrawFuncFromMethod(T& obj, void (T::*draw_func)())
    {
        return [&obj, draw_func]()
        { (obj.*draw_func)(); };
    };
    void operator()();
};

