#include "RedCommonBody.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

RedCommonBody::RedCommonBody(const TextureManager& manager):
    Body(manager.getTexture(TextureID::RedCommonBody),WIDTH_BODY,HEIGHT_BODY) {}

void RedCommonBody::render(int posX, int posY, int direction) {
    setDirection(direction);
    SDL_Rect srcHead = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstHead = {posX, posY, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void RedCommonBody::update(double dt) {
    Body::update(dt);
}

void RedCommonBody::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


RedCommonBody::~RedCommonBody(){}