#include "RedCommonBody.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

RedCommonBody::RedCommonBody(const TextureManager& manager):
    Body(manager.getTexture(TextureID::RedCommonBody),WIDTH_BODY,HEIGHT_BODY) {}

void RedCommonBody::render(int posX, int posY, int direction) {
    SDL_Rect srcHead = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstHead = {posX, posY, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void RedCommonBody::update(double dt, int animationSpeed,int totalFrames) {
    this->frame = (SDL_GetTicks()/animationSpeed) % totalFrames;
}

RedCommonBody::~RedCommonBody(){}