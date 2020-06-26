#include "Point.h"

#include <cmath>

Point::Point(float x, float y) : x(x), y(y) {}

Point& Point::operator=(const Point& p2) {
    this->x = p2.x;
    this->y = p2.y;
    return *this;
}

Point operator+(Point p1,const Point& p2) {
    return Point(p1.x+p2.x, p1.y+p2.y);
}

Point& Point::operator+=(const Point& p2) {
    this->x += p2.x;
    this->y += p2.y;
    return *this;
}

Point& Point::operator-=(const Point& p2) {
    this->x -= p2.x;
    this->y -= p2.y;
    return *this;
}

Point operator-(Point p1,const Point& p2) {
    return Point(p1.x-p2.x, p1.y-+p2.y);
}

bool operator==(Point p1,const Point& p2) {
    return (p1.x==p2.x) && (p1.y == p2.y);
}

Point operator*(const Point& p1,float n) {
    return Point(p1.x*n,p1.y*n);
}

bool operator!=(Point p1, const Point& p2) {
    return !(p1==p2);
}

float Point::distance(const Point& p2) {
    Point dist = *this - p2;
    return std::sqrt(dist.x * dist.x + dist.y * dist.y);
}