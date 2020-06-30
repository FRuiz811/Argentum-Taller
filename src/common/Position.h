#ifndef POSICION_H
#define POSICION_H


#include "Point.h"

class Position {

private: 
	float x{};
	float y{};
    float width{};
	float height{};
public:
    Position();
    Position(Point&, float, float);
	Position(float x, float y, float width, float height);

//	Position(Position&& other)  noexcept ;
//    Position& operator=(Position&& other) noexcept;

	~Position();

	Point getPoint() const;

    float getBottom() const;

    float getTop() const;

    float getRight() const;

    float getLeft() const;

    void setX(float x);

    void setY(float y);

    void setWidth(float width);

    void setHeight(float height);

    int getWidth() const;

    int getHeight() const;
};

#endif
