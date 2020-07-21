#include "Shield.h"

Shield::Shield(const Texture& texture, const int width, const int height, ShieldID id) : 
        Item(texture, width, height), id(id){}

void Shield::update(double dt, Direction dir) {
        if (this->direction != dir) {
            this->direction = dir;
            this->elapsed = 0;
        }
        this->elapsed += dt;
        this->frame = int(this->elapsed/this->animationSpeed) % this->totalFrames;
}

void Shield::setAnimationSpeed(float speed) {
        this->animationSpeed = speed;
}

ShieldID Shield::getId() const{
        return this->id;
}

Shield::~Shield() {}