#ifndef BODY_H
#define BODY_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Body: public Item {
protected:
    int frame{0};
    float elapsed{0.0};
    float animationSpeed{1.0/25.0f};
    int totalFrames{5};
    BodyID id{BodyID::Nothing};
public:
    Body(const Texture& texture, const int width, const int height, BodyID id = BodyID::Nothing) : 
        Item(texture, width, height) {}
    
    virtual void render(int posX, int posY, int direction) = 0;

    void update(double dt) {
        this->elapsed += dt;
        this->frame = int(this->elapsed/this->animationSpeed) % this->totalFrames;
    }

    void setAnimationSpeed(float speed) {
        this->animationSpeed = speed;
    }

    int getHeight() {
        return this->height;
    }

    BodyID getId(){
        return this->id;
    }

    ~Body() {};
};

#endif