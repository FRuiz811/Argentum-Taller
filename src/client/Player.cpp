#include "Player.h"
#include <SDL2/SDL.h>
#include "Items/PriestHead.h"
#include "Items/LeatherArmor.h"

Player::Player(const TextureManager& manager,int posX, int posY) 
	: center(), manager(manager), posX(posX), posY(posY) {
	this->rowBody = 0;
	this->rowHead = 1;
	this->totalFrames = 6;
	this->widthBody = 25;
	this->heightBody = 45;
	this->widthHead = 17;
	this->frameHead = 0;
	this->heightHead = 15;
	this->animSpeed = 30;
	Point aux(posX, posY);
	this->center = aux;
}

void Player::render(Camera& camera) {
	PriestHead elf(this->manager);
	LeatherArmor armor(this->manager);
    const Texture& shield = manager.getTexture(TextureID::TortleShield);
    //const Texture& helmet = manager.getTexture(TextureID::IronHelmet);
    const Texture& weapon = manager.getTexture(TextureID::AshStick);
	SDL_Rect srcHead = {widthHead*frameHead, heightHead*0, this->widthHead, this->heightHead};
	SDL_Rect dstHead = {posX+4-camera.getCameraPosition().x, (posY-heightBody/2+(heightHead-2))-camera.getCameraPosition().y,this->widthHead, this->heightHead};
   // helmet.render(srcHead,dstHead);
	SDL_Rect srcBody = {widthBody*frameBody,heightBody*rowBody, this->widthBody, this->heightBody};
	SDL_Rect dstBody = {posX-camera.getCameraPosition().x, posY-camera.getCameraPosition().y, this->widthBody, this->heightBody};
    armor.render(posX-camera.getCameraPosition().x, posY-camera.getCameraPosition().y,rowBody);
    weapon.render(srcBody,dstBody);
    shield.render(srcBody,dstBody);
	elf.render(posX+4-camera.getCameraPosition().x, (posY-heightBody/2)-camera.getCameraPosition().y, frameHead);
}

void Player::update(double dt) {
	Point aux(posX, posY);		
	this->center = aux;
	this->frameBody = (SDL_GetTicks()/this->animSpeed) % this->totalFrames;
}

void Player::handleEvent(SDL_Event& event) {
	bool needUpdate = true;
	if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        //Adjust the velocity
        switch(event.key.keysym.sym) {
            case SDLK_w: 	
				this->posY -= 32;
				rowBody = 1;
				frameHead = 3;
				this->totalFrames = 6;
				break;
            case SDLK_s: 
				this->posY += 32;
				rowBody = 0;
				frameHead = 0;
				this->totalFrames = 6;
				break;
            case SDLK_a: 
				this->posX -= 32;
				rowBody = 2;
				frameHead = 2;
				this->totalFrames = 5;
				break;
            case SDLK_d:
				this->posX += 32; 
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

Point* Player::getCenter() {
	return &center;
}

Player::~Player(){}