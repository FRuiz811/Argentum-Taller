#ifndef CHARACTER_H
#define CHARACTER_H

#include "Camera.h"
#include "../common/Identificators.h"

class Character {
protected:
	int posX, posY;
    Direction direction{Direction::down};

public:
    Character(int posX, int posY) : posX(posX), posY(posY) {}

    virtual void render(Camera& camera) = 0;

    virtual void update(double dt) = 0;

    Direction getDirection() const {
        return this->direction;
    }
    
    Point getPosition() {
        return Point(posX,posY);
    }

    ~Character() {}

};

#endif
