#include <Utils/DrawFunc/DrawFunc.hpp>

DrawFunc::DrawFunc(std::function<void()> f,int id):
func(f), id(id)
{
}
DrawFunc::DrawFunc():
func(nullptr), id(0)
{
}



DrawFunc::~DrawFunc()
{
}

void DrawFunc::operator()()
{
    func();
}