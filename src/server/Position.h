#ifndef POSICION_H
#define POSICION_H

class Position {

private: 
	int x{};
	int y{};
    int width{};
	int height{};
public:
    Position();
	Position(int x, int y, int width, int height);

	Position(Position&& other)  noexcept ;
    Position& operator=(Position&& other) noexcept ;

	~Position();

    int getBottom() const;

    int getTop() const;

    int getRight() const;

    int getLeft() const;
};

#endif
