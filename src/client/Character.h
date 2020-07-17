#ifndef CHARACTER_H
#define CHARACTER_H

#include "Camera.h"
#include "../common/Identificators.h"

class Character {
protected:
    int id;
	float posX, posY;
    Direction direction{Direction::down};

public:
    Character(float posX, float posY, int id) : id(id), posX(posX), posY(posY) {}

    virtual void render(Camera& camera) = 0;

    virtual void update(double dt) = 0;

    Direction getDirection() const {
        return this->direction;
    }
    
    Point getPosition() {
        return Point(posX,posY);
    }
    int getId() const {
        return id;
    }
    
    ~Character() {}

};

#endif
