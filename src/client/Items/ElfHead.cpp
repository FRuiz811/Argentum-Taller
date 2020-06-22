#include "ElfHead.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 16

ElfHead::ElfHead(const TextureManager& manager) :
 Head(manager.getTexture(TextureID::ElfHead),WIDTH_HEAD,HEIGHT_HEAD,HeadID::Elf) {}

void ElfHead::render(int posX, int posY, int direction) {
    SDL_Rect srcHead = {this->width*direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY+this->height-2, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

ElfHead::~ElfHead(){}