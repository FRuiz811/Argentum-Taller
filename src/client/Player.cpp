#include "Player.h"
#include "Items/ElfHead.h"
#include "Items/MagicHat.h"
#include "Items/LeatherArmor.h"
#include <SDL2/SDL.h>

Player::Player(const TextureManager& manager, PlayerInfo playerInfo)
	: center(), manager(manager), playerInfo(std::move(playerInfo)) {
    this->posX = this->playerInfo.getX();
    this->posY = this->playerInfo.getY();
	this->rowBody = 0;
	this->rowHead = 1;
	this->totalFrames = 6;
	this->widthBody = 25;
	this->heightBody = 45;
	this->widthHead = 17;
    this->heightHead = 15;
	this->frameHead = 0;
	this->animSpeed = 30;
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

void Player::moveUp() {
    this->posY -= 32;
    rowBody = 1;
    frameHead = 3;
    this->totalFrames = 6;

}
void Player::moveDown() {
    this->posY += 32;
    rowBody = 0;
    frameHead = 0;
    this->totalFrames = 6;
}

void Player::moveLeft() {
    this->posX -= 32;
    rowBody = 2;
    frameHead = 2;
    this->totalFrames = 5;
}

void Player::moveRight() {
    this->posX += 32;
    rowBody =3;
    frameHead = 1;
    this->totalFrames = 5;
}

void Player::handleEvent(SDL_Event& event, ServerProxy& serverProxy) {
	bool needUpdate = true;
	if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        //Adjust the velocity
        switch(event.key.keysym.sym) {
            case SDLK_w:
                if (serverProxy.characterMove(playerInfo.getId(), 0)) {
                    moveUp();
                }
				break;
            case SDLK_s:
                if (serverProxy.characterMove(playerInfo.getId(), 1)) {
                    moveDown();
                }
				break;
            case SDLK_a:
                if (serverProxy.characterMove(playerInfo.getId(), 2)) {
                    moveLeft();
                }
				break;
            case SDLK_d:
                if (serverProxy.characterMove(playerInfo.getId(), 3)) {
                    moveRight();
                }
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