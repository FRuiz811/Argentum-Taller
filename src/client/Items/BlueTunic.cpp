#include "BlueTunic.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

BlueTunic::BlueTunic(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::BlueTunic),WIDTH_BODY,HEIGHT_BODY,BodyID::BlueTunic) {}

void BlueTunic::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstHead = {posX, posY, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void BlueTunic::update(double dt,Direction dir) {
    setDirection(int(dir));
    Body::update(dt,dir);
}


void BlueTunic::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}

BlueTunic::~BlueTunic(){}