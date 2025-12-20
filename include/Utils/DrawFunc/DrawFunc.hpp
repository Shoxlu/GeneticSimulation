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
    static std::function<void()> GetDrawFuncFromMethod(T& obj, void (T::*f)())
    {
        return [&obj, f]()
        { (obj.*f)(); };
    };
    void operator()();
};

