#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Weapon: public Item {
protected:
    int frame{0};
    float elapsed{0.0};
    float animationSpeed{40.0f};
    int totalFrames{5};
    WeaponID id{WeaponID::Nothing};
public:
    Weapon(const Texture& texture, const int width, const int height, WeaponID id = WeaponID::Nothing) : 
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

    WeaponID getId(){
        return this->id;
    }

    ~Weapon() {};
};

#endif