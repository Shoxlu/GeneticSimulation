#pragma once
#include <cmath>

class Vec
{
private:
public:
    Vec();
    Vec(double x, double y);
    ~Vec();
    double x, y;

    //Operators
    Vec& operator+=(const Vec& other);
    Vec& operator-=(const Vec& other);
    Vec& operator*=(double scalar);
    Vec& operator/=(double scalar);
    Vec operator-();
};

Vec operator+(Vec a, const Vec& b);
Vec operator-(Vec a, const Vec& b);
Vec operator*(Vec a, float scalar);
Vec operator*(float scalar, Vec a);
Vec operator/(Vec a, float scalar);
double dot(const Vec& a,const Vec& b);
double dist_sq(const Vec& a,const Vec& b);
double dist(const Vec& a,const Vec& b);