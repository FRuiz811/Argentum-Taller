#include "Zombie.h"
#include <SDL2/SDL.h>

Zombie::Zombie(const TextureManager& manager) : manager(manager) {
	this->rowBody = 0;
	this->rowHead = 1;
	this->totalFrames = 6;
	this->widthBody = 25;
	this->heightBody = 45;
	this->widthHead = 17;
	this->frameHead = 0;
	this->heightHead = 15;
	this->animSpeed = 80;
	this->posX = 0;
	this->posY = 0;
}

void Zombie::render(const int width_screen, const int height_screen) {
	const Texture& head = manager.getTexture(TextureID::ZombieHead);
	const Texture& body = manager.getTexture(TextureID::ZombieBody);
	SDL_Rect srcHead = {widthHead*frameHead, heightHead*0, this->widthHead, this->heightHead};
	SDL_Rect dstHead = {((width_screen+9)/2)+posX,((height_screen/2)-(this->heightHead+1)/2)+posY,this->widthHead, this->heightHead};
	head.render(srcHead, dstHead);
	SDL_Rect srcBody = {widthBody*frameBody,heightBody*rowBody, this->widthBody, this->heightBody};
	SDL_Rect dstBody = {(width_screen/2)+posX, (height_screen/2)+posY, this->widthBody, this->heightBody};
	body.render(srcBody, dstBody);
}

void Zombie::update(double dt) {
	this->frameBody = (SDL_GetTicks()/this->animSpeed) % this->totalFrames;
}

void Zombie::handleEvent(SDL_Event& event) {
	bool needUpdate = true;
	if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        //Adjust the velocity
        switch(event.key.keysym.sym) {
            case SDLK_UP: 	
				this->posY -= 5;
				rowBody = 1;
				frameHead = 3;
				this->totalFrames = 6;
				break;
            case SDLK_DOWN: 
				this->posY += 5;
				rowBody = 0;
				frameHead = 0;
				this->totalFrames = 6;
				break;
            case SDLK_LEFT: 
				this->posX -= 5;
				rowBody = 2;
				frameHead = 2;
				this->totalFrames = 5;
				break;
            case SDLK_RIGHT:
				this->posX += 5; 
				rowBody =3;
				frameHead = 1;
				this->totalFrames = 5;
				break;
			default:
				needUpdate = false;
		}
		if (needUpdate)
			update(0);
	}

}

Zombie::~Zombie(){}