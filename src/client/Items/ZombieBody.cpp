#include "ZombieBody.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

ZombieBody::ZombieBody(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::ZombieBody),WIDTH_BODY,HEIGHT_BODY,BodyID::Zombie) {}

void ZombieBody::render(int posX, int posY) {
    SDL_Rect srcBody = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void ZombieBody::update(double dt,Direction dir) {
    setDirection(int(dir));
    Body::update(dt,dir);
}

void ZombieBody::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}

ZombieBody::~ZombieBody(){}