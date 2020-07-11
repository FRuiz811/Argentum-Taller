#include "GoblinBody.h"

#define WIDTH_BODY 24
#define HEIGHT_BODY 31

GoblinBody::GoblinBody(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::Goblin),WIDTH_BODY,HEIGHT_BODY, BodyID::Goblin) {
     this->totalFrames = 8;
 }

void GoblinBody::render(int posX, int posY) {
    SDL_Rect srcBody = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void GoblinBody::update(double dt,Direction dir) {
    setDirection(int(dir));
    Body::update(dt,dir);
}

void GoblinBody::setDirection(int direction) {}

GoblinBody::~GoblinBody(){}