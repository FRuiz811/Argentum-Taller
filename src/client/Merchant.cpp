#include "Merchant.h"
#include <SDL2/SDL.h>

Merchant::Merchant(const TextureManager& manager, int posX, int posY) : 
	Character(posX,posY), body(manager) {}

void Merchant::render(Camera& camera) {
	body.render(posX-camera.getCameraPosition().x, posY-camera.getCameraPosition().y,directionBody);
}

void Merchant::update(double dt) {
	this->body.update(dt);
}

void Merchant::handleEvent(SDL_Event& event) {
    bool needUpdate =true;
	if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        //Adjust the velocity
        switch(event.key.keysym.sym) {
            case SDLK_w: 	
				this->posY -= 5;
				directionBody = 1;
				break;
            case SDLK_s: 
				this->posY += 5;
				directionBody = 0;
				break;
            case SDLK_a: 
				this->posX -= 5;
				directionBody = 2;
				break;
            case SDLK_d:
				this->posX += 5; 
				directionBody = 3;
				break;
		default:
				needUpdate = false;
		}
		if (needUpdate)
			update(0);
	}
}

Merchant::~Merchant(){}