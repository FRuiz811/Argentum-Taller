#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Weapon: public Item {
protected:
    int frame{0};
    float elapsed{0.0};
    float animationSpeed{30.0f};
    int totalFrames{5};
    WeaponID id{WeaponID::Nothing};
    Direction direction{Direction::down};
public:
    Weapon(const Texture& texture, const int width, const int height, WeaponID id = WeaponID::Nothing) : 
        Item(texture, width, height), id(id) {}
    
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

    int getHeight() {
        return this->height;
    }

    WeaponID getId(){
        return this->id;
    }

    ~Weapon() {};
};

#endif