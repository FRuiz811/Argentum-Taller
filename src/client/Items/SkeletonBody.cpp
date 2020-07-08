#include "SkeletonBody.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 52

SkeletonBody::SkeletonBody(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::Skeleton),WIDTH_BODY,HEIGHT_BODY,BodyID::Skeleton) {}

void SkeletonBody::render(int posX, int posY, int direction) {
    setDirection(direction);
    SDL_Rect srcBody = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstBody = {posX, posY, int(this->width*1.5), int(this->height*1.5)};
    this->texture.render(srcBody, dstBody);
}

void SkeletonBody::update(double dt) {
    Body::update(dt);
}

void SkeletonBody::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}

SkeletonBody::~SkeletonBody(){}