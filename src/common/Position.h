#ifndef POSICION_H
#define POSICION_H

#include "../client/Point.h"

class Position {

private: 
	int x{};
	int y{};
    int width{};
	int height{};
public:
    Position();
    Position(Point&, int, int);
	Position(int x, int y, int width, int height);

//	Position(Position&& other)  noexcept ;
//    Position& operator=(Position&& other) noexcept;

	~Position();

	Point getPoint() const;

    int getBottom() const;

    int getTop() const;

    int getRight() const;

    int getLeft() const;

    void setX(int x);

    void setY(int y);

    void setWidth(int width);

    void setHeight(int height);
};

#endif
