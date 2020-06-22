#include "IronShield.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

IronShield::IronShield(const TextureManager& manager) :
 Shield(manager.getTexture(TextureID::IronShield),WIDTH_BODY,HEIGHT_BODY) {}

void IronShield::render(int posX, int posY, int direction) {
    setDirection(direction);
    SDL_Rect srcBody = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void IronShield::update(double dt) {
    Shield::update(dt);
}

void IronShield::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}

IronShield::~IronShield(){}