#include "Player.h"
#include <SDL2/SDL.h>
#include "Items/ElfHead.h"
#include "Items/LeatherArmor.h"
#include "Items/MagicHat.h"
#include "CharacterStates/StillState.h"
#include "CharacterStates/MoveState.h"
#include "CharacterStates/DeadState.h"
#include "CharacterStates/StartMovingState.h"

#define PLAYER_VEL 3

Player::Player(const TextureManager& manager,int posX, int posY) 
	: center(), manager(manager), posX(posX), posY(posY) {
	setState(CharacterStateID::Still);
	this->rowBody = 0;
	this->rowHead = 1;
	this->totalFrames = 6;
	this->widthBody = 25;
	this->heightBody = 45;
	this->widthHead = 17;
	this->frameHead = 0;
	this->heightHead = 15;
	this->animSpeed = 25;
	Point aux(posX, posY);
	this->center = aux;
	this->body = std::shared_ptr<Body>(new LeatherArmor(this->manager));
}

void Player::render(Camera& camera) {
	ElfHead elf(this->manager);
	MagicHat hat(this->manager);
    const Texture& shield = manager.getTexture(TextureID::IronShield);

    const Texture& weapon = manager.getTexture(TextureID::LongSword);
	SDL_Rect srcHead = {widthHead*frameHead, heightHead*0, this->widthHead, this->heightHead};
	SDL_Rect dstHead = {int(posX+4-camera.getCameraPosition().x), int((posY-heightBody/2+(heightHead-2))-camera.getCameraPosition().y),this->widthHead, this->heightHead};
   // helmet.render(srcHead,dstHead);
	SDL_Rect srcBody = {widthBody*frameBody,heightBody*rowBody, this->widthBody, this->heightBody};
	SDL_Rect dstBody = {int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y), this->widthBody, this->heightBody};
  	this->body->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y),rowBody);
    weapon.render(srcBody,dstBody);
    shield.render(srcBody,dstBody);
	elf.render(int(posX+4-camera.getCameraPosition().x), int((posY-heightBody/2)-camera.getCameraPosition().y), frameHead);
	hat.render(int(posX+4-camera.getCameraPosition().x), int((posY-heightBody/2)-camera.getCameraPosition().y), frameHead);
}

void Player::update(double dt) {
	Point aux(posX, posY);		
	this->center = aux;
	this->body->update(dt);
	this->frameBody = (SDL_GetTicks()/this->animSpeed) % this->totalFrames;
}

void Player::handleEvent(SDL_Event& event) {
	bool needUpdate = true;
	if(event.type == SDL_KEYDOWN) {
        //Adjust the velocity
        switch(event.key.keysym.sym) {
            case SDLK_w: 	
				this->posY -= PLAYER_VEL;
				rowBody = 1;
				frameHead = 3;
				this->totalFrames = 6;
				break;
            case SDLK_s: 
				this->posY += PLAYER_VEL;
				rowBody = 0;
				frameHead = 0;
				this->totalFrames = 6;
				break;
            case SDLK_a: 
				this->posX -= PLAYER_VEL;
				rowBody = 2;
				frameHead = 2;
				this->totalFrames = 5;
				break;
            case SDLK_d:
				this->posX += PLAYER_VEL; 
				rowBody =3;
				frameHead = 1;
				this->totalFrames = 5;
				break;
			case SDLK_r:
				break;
			case SDLK_g:
				break;
			case SDLK_b:
				break;
			case SDLK_v:
				break;
			case SDLK_f:
				break;
			default:
				needUpdate = false;
		}
	} else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
		switch(event.key.keysym.sym) {
			case SDLK_w: 	
				this->posY += PLAYER_VEL;
				break;
            case SDLK_s: 
				this->posY -= PLAYER_VEL;
				break;
            case SDLK_a: 
				this->posX += PLAYER_VEL;
				break;
            case SDLK_d:
				this->posX -= PLAYER_VEL; 
				break;
		}
	}
	if (needUpdate)
		update(0);
}

void Player::setState(CharacterStateID newState) {
	if(this->state == nullptr || this->state->getState() != newState) {
		switch (newState) {
			case CharacterStateID::Still:
				this->state = std::shared_ptr<CharacterState>(new StillState());
				break;
			case CharacterStateID::StartMoving:
				this->state = std::shared_ptr<CharacterState>(new StartMovingState());
				break;
			case CharacterStateID::Move:
				this->state = std::shared_ptr<CharacterState>(new MoveState());
				break;
			case CharacterStateID::Dead:
				this->state = std::shared_ptr<CharacterState>(new DeadState());
				break;
		}
	}
}


Point* Player::getCenter() {
	return &center;
}

Player::~Player(){}