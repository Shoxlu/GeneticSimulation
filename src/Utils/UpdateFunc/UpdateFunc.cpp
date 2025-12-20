#include <Utils/UpdateFunc/UpdateFunc.hpp>

UpdateFunc::UpdateFunc(std::function<void()> f,int id):
func(f), id(id)
{
}

UpdateFunc::UpdateFunc():
func(nullptr), id(0)
{
}


UpdateFunc::~UpdateFunc()
{
}

void UpdateFunc::operator()()
{
    func();
}