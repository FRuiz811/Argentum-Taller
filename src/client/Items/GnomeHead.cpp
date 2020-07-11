#include "GnomeHead.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 16

GnomeHead::GnomeHead(const TextureManager& manager) :
 Head(manager.getTexture(TextureID::GnomeHead),WIDTH_HEAD,HEIGHT_HEAD,HeadID::Gnome) {}

void GnomeHead::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*this->direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY+this->height-2, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void GnomeHead::update(int dir){
    this->direction = dir;
}

GnomeHead::~GnomeHead(){}