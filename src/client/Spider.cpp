#include "Spider.h"
#include <SDL2/SDL.h>

Spider::Spider(const TextureManager& manager) : manager(manager) {
	this->width = 53;
    this->height = 35;
    this->row = 0;
    this->animSpeed = 80;
    this->totalFrames = 4;
    this->posY = 0;
    this->posX = 0;
}

void Spider::render(const int width_screen, const int height_screen) {
	const Texture& spider = manager.getTexture(TextureID::Spider);
	SDL_Rect src = {width*frame,height*row, this->width, this->height};
	SDL_Rect dst = {(width_screen/4)+posX, (height_screen/4)+posY, this->width, this->height};
	spider.render(src, dst);
}

void Spider::update(double dt) {
	this->frame = (SDL_GetTicks()/this->animSpeed) % this->totalFrames;
}

void Spider::handleEvent(SDL_Event& event) {
    bool needUpdate =true;
	if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        //Adjust the velocity
        switch(event.key.keysym.sym) {
            case SDLK_w: 	
				this->posY -= 5;
				row = 1;
				break;
            case SDLK_s: 
				this->posY += 5;
				row = 0;
				break;
            case SDLK_a: 
				this->posX -= 5;
				row = 2;
				break;
            case SDLK_d:
				this->posX += 5; 
				row = 3;
				break;
		default:
				needUpdate = false;
		}
		if (needUpdate)
			update(0);
	}
}

Spider::~Spider(){}