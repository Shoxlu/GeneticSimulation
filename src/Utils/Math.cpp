#include <Utils/Math.hpp>
#define _USE_MATH_DEFINES
#include <cmath>

double deg(double angle){
    return angle * 180 / M_PI;
}
double rad(double angle){
    return angle / 180 * M_PI;
}

double normalize_angle(double angle)
{
    while (angle >= M_PI)
    {
        angle -= 2 * M_PI;
    }
    while (angle <= -M_PI)
    {
        angle += 2 * M_PI;
    }
    return angle;
}