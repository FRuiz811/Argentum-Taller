#include "PlateArmor.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

PlateArmor::PlateArmor(const TextureManager& manager) :
 Body(manager.getTexture(TextureID::PlateArmor),WIDTH_BODY,HEIGHT_BODY,BodyID::PlateArmor) {}

void PlateArmor::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstHead = {posX, posY, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void PlateArmor::update(double dt,Direction dir) {
    setDirection(int(dir));
    Body::update(dt,dir);
}

void PlateArmor::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


PlateArmor::~PlateArmor(){}