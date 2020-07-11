#include "BankerBody.h"
#include "../TextureID.h"
#include "../../common/Identificators.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

BankerBody::BankerBody(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::Banker),WIDTH_BODY,HEIGHT_BODY,BodyID::Banker) {}

void BankerBody::render(int posX, int posY) {
    SDL_Rect srcBody = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstBody = {posX, posY, this->width, this->height};
    this->texture.render(srcBody, dstBody);
}

void BankerBody::update(double dt,Direction dir) {
    setDirection(int(dir));
    Body::update(dt,dir);
}

void BankerBody::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}

BankerBody::~BankerBody()= default;