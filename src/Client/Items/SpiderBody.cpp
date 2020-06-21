#include "SpiderBody.h"
#include "../TextureID.h"

#define WIDTH_BODY 53
#define HEIGHT_BODY 35

SpiderBody::SpiderBody(const TextureManager& manager):
    Body(manager.getTexture(TextureID::Spider),WIDTH_BODY,HEIGHT_BODY) {}

void SpiderBody::render(int posX, int posY, int direction) {
    SDL_Rect srcBody = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void SpiderBody::update(double dt) {
    Body::update(dt);
}

SpiderBody::~SpiderBody(){}