#pragma once
#include <Logic/Objects/Object.hpp>
#include <vector>

class ObjectManager
{
private:
    /* data */
public:
    static std::vector<Object> CreateRandomSet(const int n_obj,const Vec& x_range, const Vec& y_range);
    static void RandomizeSet(std::vector<Object>& objects, const Vec& x_range, const Vec& y_range);
    static void AddToDrawQueue(Object &obj);
    ObjectManager();
    ~ObjectManager();
};


