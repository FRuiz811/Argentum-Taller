#ifndef BODY_H
#define SHIELD_H

#include "Item.h"
#include "../Texture.h"

class Shield: public Item {
protected:
    int frame{0};
    float animationSpeed{25.0f};
    int totalFrames{5};
public:
    Shield(const Texture& texture, const int width, const int height) : 
        Item(texture, width, height){}
    
    virtual void render(int posX, int posY, int direction) = 0;

    void update(double dt) {
        this->frame = int(SDL_GetTicks()/this->animationSpeed) % this->totalFrames;
    }

    void setAnimationSpeed(float speed) {
        this->animationSpeed = speed;
    }

    ~Shield() {};
};

#endif