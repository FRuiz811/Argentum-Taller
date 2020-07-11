#include "DwarfHead.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 19

DwarfHead::DwarfHead(const TextureManager& manager) :
 Head(manager.getTexture(TextureID::DwarfHead),WIDTH_HEAD,HEIGHT_HEAD,HeadID::Dwarf) {}

void DwarfHead::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*this->direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY+this->height-2, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void DwarfHead::update(int dir){
    this->direction = dir;
}

DwarfHead::~DwarfHead(){}