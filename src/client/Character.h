#ifndef CHARACTER_H
#define CHARACTER_H

#include "Camera.h"

class Character {
protected:
	int posX, posY, directionBody{0};

public:
    Character(int posX, int posY) : posX(posX), posY(posY) {}
        
    virtual void render(Camera& camera) = 0;

    virtual void update(double dt) = 0;

    ~Character() {}

};

#endif
