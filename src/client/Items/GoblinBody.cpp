#include "GoblinBody.h"
#include "../TextureID.h"

#define WIDTH_BODY 24
#define HEIGHT_BODY 30

GoblinBody::GoblinBody(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::Goblin),WIDTH_BODY,HEIGHT_BODY) {
     this->totalFrames = 8;
 }

void GoblinBody::render(int posX, int posY, int direction) {
    setDirection(direction);
    SDL_Rect srcBody = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void GoblinBody::update(double dt) {
    Body::update(dt);
}

void GoblinBody::setDirection(int direction) {}

GoblinBody::~GoblinBody(){}