#ifndef POINT_H
#define POINT_H
#include <math.h>

class Point {
public:
    float x,y;

    Point(float x=0, float y=0);

    Point& operator=(const Point& p2);

    friend Point operator+(Point p1, const Point& p2);

    Point& operator +=(const Point& p2);

    friend Point operator-(Point p1, const Point& p2);

    Point& operator-=(const Point& p2); 

    friend Point operator*(const Point& p1, float n);

    friend bool operator==(Point p1, const Point& p2);

    friend bool operator!=(Point p1, const Point& p2);

    float distance(const Point& p2);
};

#endif