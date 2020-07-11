#include "IronHelmet.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 16

IronHelmet::IronHelmet(const TextureManager& manager) :
 Helmet(manager.getTexture(TextureID::IronHelmet),WIDTH_HEAD,HEIGHT_HEAD, HelmetID::IronHelmet) {}

void IronHelmet::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*this->direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY+this->height-2, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void IronHelmet::update(int dir) {
    this->direction = dir;
}

IronHelmet::~IronHelmet(){}