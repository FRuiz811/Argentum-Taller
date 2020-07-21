#include "Weapon.h"

Weapon::Weapon(const Texture& texture, const int width, const int height, WeaponID id) : 
        Item(texture, width, height), id(id) {}

void Weapon::update(double dt, Direction dir) {
        if (this->direction != dir) {
            this->direction = dir;
            this->elapsed = 0;
        }
        this->elapsed += dt;
        this->frame = int(this->elapsed/this->animationSpeed) % this->totalFrames;
}

void Weapon::setAnimationSpeed(float speed) {
        this->animationSpeed = speed;
}

int Weapon::getHeight() const {
        return this->height;
}

WeaponID Weapon::getId() const {
        return this->id;
}

Weapon::~Weapon() {}