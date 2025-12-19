#include <Utils/DrawFunc/DrawFunc.hpp>

DrawFunc::DrawFunc(std::function<void()> f, int priority,int id):
func(f), id(id), priority(priority)
{
}

DrawFunc::~DrawFunc()
{
}

void DrawFunc::operator()()
{
    func();
}