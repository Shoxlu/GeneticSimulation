#include <Utils/UpdateFunc/UpdateFunc.hpp>

UpdateFunc::UpdateFunc(std::function<void()> f, int priority,int id):
func(f), id(id), priority(priority)
{
}

UpdateFunc::~UpdateFunc()
{
}

void UpdateFunc::operator()()
{
    func();
}