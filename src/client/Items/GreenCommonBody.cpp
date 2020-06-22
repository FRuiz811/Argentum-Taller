#include "GreenCommonBody.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

GreenCommonBody::GreenCommonBody(const TextureManager& manager):
    Body(manager.getTexture(TextureID::GreenCommonBody),WIDTH_BODY,HEIGHT_BODY, BodyID::GreenCommon) {}

void GreenCommonBody::render(int posX, int posY, int direction) {
    setDirection(direction);
    SDL_Rect srcHead = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstHead = {posX, posY, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void GreenCommonBody::update(double dt) {
    Body::update(dt);
}

void GreenCommonBody::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


GreenCommonBody::~GreenCommonBody(){}
