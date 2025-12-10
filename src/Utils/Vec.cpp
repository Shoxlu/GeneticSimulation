#include <Utils/Vec.hpp>


Vec::Vec():x(0), y(0)
{

}

Vec::Vec(double x, double y): x(x), y(y)
{

}

Vec::~Vec(){

}

bool Vec::operator==(const Vec& other){
    return x == other.x && y == other.y;
}

bool Vec::operator!=(const Vec& other){
    return !(*this == other);
}


Vec& Vec::operator+=(const Vec& other){
    x+=other.x;
    y+=other.y;
    return *this;
}

Vec& Vec::operator-=(const Vec& other){
    x-=other.x;
    y-=other.y;
    return *this;
}

Vec Vec::operator-(){
    return Vec(-x,-y);
}

Vec& Vec::operator*=(double scalar){
    x*=scalar;
    y*=scalar;
    return *this;
}

Vec& Vec::operator/=(double scalar){
    x/=scalar;
    y/=scalar;
    return *this;
}

Vec Vec::operator+(const Vec& b) const {
    return Vec(x+b.x, y+b.y);
}

Vec Vec::operator-(const Vec& b) const{
    return Vec(x-b.x, y-b.y);
}

Vec operator*(float scalar, Vec a){
    a*=scalar;
    return a;
}

Vec operator*(Vec a, float scalar){
    a*=scalar;
    return a;
}

Vec Vec::operator/(float scalar){
    return Vec(x/scalar, y/scalar);
}

double dot(const Vec& a,const Vec& b){
    return a.x*b.x+a.y*b.y;
}

double dist_sq(const Vec& a,const Vec& b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

double dist(const Vec& a,const Vec& b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


