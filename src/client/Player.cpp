#include "Player.h"
#include "Items/ElfHead.h"
#include "Items/HumanHead.h"
#include "Items/DwarfHead.h"
#include "Items/GnomeHead.h"
#include "Items/MagicHat.h"
#include "Items/Hood.h"
#include "Items/IronHelmet.h"
#include "Items/IronShield.h"
#include "Items/TurtleShield.h"
#include "Items/LeatherArmor.h"
#include "Items/BlueCommonBody.h"
#include "Items/RedCommonBody.h"
#include "Items/GreenCommonBody.h"
#include "Items/PlateArmor.h"
#include "Items/BlueTunic.h"
#include <SDL2/SDL.h>
#include "characterStates/StillState.h"
#include "characterStates/MoveState.h"
#include "characterStates/DeadState.h"
#include "characterStates/StartMovingState.h"

Player::Player(const TextureManager& manager, PlayerInfo playerInfo) :
	Character(playerInfo.getX(),playerInfo.getY()), center(playerInfo.getX(),playerInfo.getY()),
    manager(manager), playerInfo(std::move(playerInfo)) {
	this->frameHead = 0;
	setArmor((BodyID)3);
	setHead((HeadID)3);
	setHelmet((HelmetID)2);
	setShield((ShieldID)2);
}

void Player::render(Camera& camera) {
	if(this->isAlive){
 	 	this->body->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y),this->directionBody);
	  if (this->shield != nullptr)
		  this->shield->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y),this->directionBody);
   // if (this->weapon != nullptr)
   //     this->weapon->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y),this->directionBody);
    this->head->render(int(posX+4-camera.getCameraPosition().x), int((posY-this->body->getHeight()/2)-camera.getCameraPosition().y), this->frameHead);
    if (this->helmet != nullptr)
        this->helmet->render(int(posX+4-camera.getCameraPosition().x), int((posY-this->body->getHeight()/2)-camera.getCameraPosition().y), this->frameHead);
	} else {

	}
}

void Player::update(double dt) {
    Point aux(posX, posY);
    this->center = aux;
    this->body->update(dt);
    if (this->shield != nullptr)
        this->shield->update(dt);
    //if (this->weapon != nullptr)
    //    this->weapon->update(dt);
}

void Player::moveUp() {
    this->posY -= 15;
    frameHead = 3;
		directionBody = 1;

}
void Player::moveDown() {
    this->posY += 15;
    frameHead = 0;
		directionBody = 0;

}

void Player::moveLeft() {
    this->posX -= 15;
    frameHead = 2;
		directionBody = 2;
}

void Player::moveRight() {
    this->posX += 15;
    frameHead = 1;
		directionBody = 3;
}

void Player::handleEvent(SDL_Event& event, ServerProxy& serverProxy) {
	bool needUpdate = true;
	if(event.type == SDL_KEYDOWN) {
    //Adjust the velocity
    switch(event.key.keysym.sym) {
      case SDLK_w:
        //this->state->moveUp(*this);
        if (serverProxy.characterMove(playerInfo.getId(), 0)) {
          moveUp();
        }
				break;
    	case SDLK_s:
				//this->state->moveDown(*this);
        if (serverProxy.characterMove(playerInfo.getId(), 1)) {
          moveDown();
        }
				break;
      case SDLK_a:
				//this->state->moveLeft(*this);
        if (serverProxy.characterMove(playerInfo.getId(), 2)) {
  		    moveLeft();
        }
				break;
      case SDLK_d:
				//this->state->moveRight(*this);
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
				this->isAlive = false;
				break;
		}
	}
}

void Player::setHead(HeadID head) {
	if (this->head == nullptr || head != this->head->getId()) {
	  switch (head) {
    	case HeadID::Elf:
        this->head = std::shared_ptr<Head>(new ElfHead(this->manager));
        break;
      case HeadID::Human:
        this->head = std::shared_ptr<Head>(new HumanHead(this->manager));
        break;
			case HeadID::Dwarf:
        this->head = std::shared_ptr<Head>(new DwarfHead(this->manager));
        break;
			case HeadID::Gnome:
        this->head = std::shared_ptr<Head>(new GnomeHead(this->manager));
        break;
    }
  }
}

void Player::setArmor(BodyID newArmor) {
  if (this->body == nullptr || newArmor != this->body->getId()) {
	  switch (newArmor) {
    	case BodyID::BlueCommon:
        this->body = std::shared_ptr<Body>(new BlueCommonBody(this->manager));
        break;
      case BodyID::RedCommon:
        this->body = std::shared_ptr<Body>(new RedCommonBody(this->manager));
        break;
			case BodyID::GreenCommon:
        this->body = std::shared_ptr<Body>(new GreenCommonBody(this->manager));
        break;
			case BodyID::BlueTunic:
        this->body = std::shared_ptr<Body>(new BlueTunic(this->manager));
        break;
			case BodyID::LeatherArmor:
        this->body = std::shared_ptr<Body>(new LeatherArmor(this->manager));
        break;
			case BodyID::PlateArmor:
        this->body = std::shared_ptr<Body>(new PlateArmor(this->manager));
        break;
    }
  }
}

void Player::setHelmet(HelmetID newHelmet) {
  if (this->helmet == nullptr || newHelmet != this->helmet->getId()) {
	  switch (newHelmet) {
    	case HelmetID::Nothing:
        this->helmet = nullptr;
        break;
      case HelmetID::Hood:
        this->helmet = std::shared_ptr<Helmet>(new Hood(this->manager));
        break;
			case HelmetID::IronHelmet:
        this->helmet = std::shared_ptr<Helmet>(new IronHelmet(this->manager));
        break;
			case HelmetID::MagicHat:
        this->helmet = std::shared_ptr<Helmet>(new MagicHat(this->manager));
        break;
    }
  }
}

void Player::setShield(ShieldID newShield) {
	if (this->shield == nullptr || newShield != this->shield->getId()){
		switch (newShield) {
    	case ShieldID::Nothing:
        this->shield = nullptr;
        break;
      case ShieldID::TurtleShield:
        this->shield = std::shared_ptr<Shield>(new TurtleShield(this->manager));
        break;
			case ShieldID::IronShield:
        this->shield = std::shared_ptr<Shield>(new IronShield(this->manager));
        break;
		}
	}

}

Point* Player::getCenter() {
	return &center;
}

Player::~Player(){}