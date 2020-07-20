#include "Body.h"

Body::Body(const Texture& texture, const int width, const int height, BodyID id = BodyID::Nothing) : 
        Item(texture, width, height), id(id) {}

 void Body::update(double dt, Direction dir) {
        if (this->direction != dir) {
            this->direction = dir;
            this->elapsed = 0;
        }
        this->elapsed += dt;
        this->frame = int(this->elapsed/this->animationSpeed) % this->totalFrames;
}

void Body::setAnimationSpeed(float speed) {
        this->animationSpeed = speed;
}

int Body::getHeight() const{
        return this->height;
}

BodyID Body::getId() const{
        return this->id;
}

Body::~Body() {}