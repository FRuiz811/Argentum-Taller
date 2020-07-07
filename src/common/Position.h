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

	~Position();

	Point getPoint() const;

    float getBottom() const;

    float getTop() const;

    float getRight() const;

    float getLeft() const;

    float getMiddle() const;

    float distance(Position& other);

    float getWidth() const;

    float getHeight() const;
};

#endif
