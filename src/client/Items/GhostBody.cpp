#include "GhostBody.h"

#define WIDTH_BODY 29
#define HEIGHT_BODY 32

GhostBody::GhostBody(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::Ghost),WIDTH_BODY,HEIGHT_BODY,BodyID::Ghost) {
     this->totalFrames = 3;
 }

void GhostBody::render(int posX, int posY) {
    SDL_Rect srcBody = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void GhostBody::update(double dt,Direction dir) {
    setDirection(int(dir));
    Body::update(dt,dir);
}

void GhostBody::setDirection(int direction) {}

GhostBody::~GhostBody(){}