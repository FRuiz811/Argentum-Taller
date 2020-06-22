#include "Priest.h"

Priest::Priest(const TextureManager& manager,int posX, int posY) : 
	Character(posX,posY), body(manager), head(manager) {
	this->frameHead = 0;
}

void Priest::render(Camera& camera) {
	this->body.render(posX-camera.getCameraPosition().x, posY-camera.getCameraPosition().y,directionBody);
	this->head.render(posX+4-camera.getCameraPosition().x, posY-camera.getCameraPosition().y-45/2,frameHead);
}

void Priest::update(double dt) {
	this->body.update(dt);
}

void Priest::handleEvent(SDL_Event& event) {
	bool needUpdate = true;
	if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        //Adjust the velocity
        switch(event.key.keysym.sym) {
            case SDLK_UP: 	
				this->posY -= 5;
				directionBody = 1;
				frameHead = 3;
				break;
            case SDLK_DOWN: 
				this->posY += 5;
				directionBody = 0;
				frameHead = 0;
				break;
            case SDLK_LEFT: 
				this->posX -= 5;
				directionBody = 2;
				frameHead = 2;
				break;
            case SDLK_RIGHT:
				this->posX += 5; 
				directionBody =3;
				frameHead = 1;
				break;
			default:
				needUpdate = false;
		}
		if (needUpdate)
			update(0);
	}

}

Priest::~Priest(){}