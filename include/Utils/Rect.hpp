#pragma once
#include <Utils/Vec.hpp>
class Rect
{
private:


public:
    Vec pos;
    Vec size;
    Rect() : pos(0, 0), size(0, 0)
    {

    }
    Rect(const Vec& pos, const Vec& size): pos(pos), size(size)
    {
    }
};