#include "SpiderBody.h"

#define WIDTH_BODY 53
#define HEIGHT_BODY 35

SpiderBody::SpiderBody(const TextureManager& manager):
    Body(manager.getTexture(TextureID::Spider),WIDTH_BODY,HEIGHT_BODY,BodyID::Spider) {
        this->totalFrames = 4;
    }

void SpiderBody::render(int posX, int posY) {
    SDL_Rect srcBody = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void SpiderBody::update(double dt,Direction dir) {
    Body::update(dt,dir);
}

SpiderBody::~SpiderBody(){}