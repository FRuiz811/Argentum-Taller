#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Shield: public Item {
protected:
    int frame{0};
    float elapsed{0.0};
    float animationSpeed{30.0f};
    int totalFrames{5};
    ShieldID id{ShieldID::Nothing};
    Direction direction{Direction::down};
public:
    Shield(const Texture& texture, const int width, const int height, ShieldID id = ShieldID::Nothing) : 
        Item(texture, width, height), id(id){}
    
    virtual void render(int posX, int posY) = 0;

    void update(double dt, Direction dir) {
        if (this->direction != dir) {
            this->direction = dir;
            this->elapsed = 0;
        }
        this->elapsed += dt;
        this->frame = int(this->elapsed/this->animationSpeed) % this->totalFrames;
    }

    void setAnimationSpeed(float speed) {
        this->animationSpeed = speed;
    }

    ShieldID getId(){
        return this->id;
    }

    ~Shield() {};
};

#endif