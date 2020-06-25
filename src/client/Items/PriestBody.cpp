#include "PriestBody.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

PriestBody::PriestBody(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::PriestBody),WIDTH_BODY,HEIGHT_BODY) {}

void PriestBody::render(int posX, int posY, int direction) {
    setDirection(direction);
    SDL_Rect srcBody = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void PriestBody::update(double dt) {
    Body::update(dt);
}

void PriestBody::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}

PriestBody::~PriestBody(){}