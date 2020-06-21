#include "BlueCommonBody.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

BlueCommonBody::BlueCommonBody(const TextureManager& manager):
    Body(manager.getTexture(TextureID::BlueCommonBody),WIDTH_BODY,HEIGHT_BODY) {}

void BlueCommonBody::render(int posX, int posY, int direction) {
    SDL_Rect srcHead = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstHead = {posX, posY, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void BlueCommonBody::update(double dt, int animationSpeed,int totalFrames) {
    this->frame = (SDL_GetTicks()/animationSpeed) % totalFrames;
}

BlueCommonBody::~BlueCommonBody(){}