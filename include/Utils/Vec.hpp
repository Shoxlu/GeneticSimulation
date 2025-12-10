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
    bool operator==(const Vec &other);
    bool operator!=(const Vec &other);
    Vec operator-();
    Vec operator+(const Vec& b) const;
    Vec operator-(const Vec& b) const;
    Vec operator/(float scalar);
};

Vec operator*(Vec a, float scalar);
Vec operator*(float scalar, Vec a);
double dot(const Vec& a,const Vec& b);
double dist_sq(const Vec& a,const Vec& b);
double dist(const Vec& a,const Vec& b);