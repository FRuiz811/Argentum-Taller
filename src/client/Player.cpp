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
#include "Items/GhostBody.h"
#include "Items/PlateArmor.h"
#include "Items/BlueTunic.h"
#include "Items/Ax.h"
#include "Items/AshStick.h"
#include "Items/Crosier.h"
#include "Items/ElficFlaute.h"
#include "Items/SimpleArc.h"
#include "Items/CompoundArc.h"
#include "Items/LongSword.h"
#include "Items/Hammer.h"
#include "Items/GnarledStick.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "characterStates/StillState.h"
#include "characterStates/MoveState.h"
#include "characterStates/DeadState.h"
#include "characterStates/MeditateState.h"
#include "characterStates/InteractState.h"
#include "characterStates/AttackState.h"


Player::Player(const TextureManager& manager, const PlayerInfo& playerInfo) :
  Character(playerInfo.getX(),playerInfo.getY(),playerInfo.getId()),
  center(playerInfo.getX(),playerInfo.getY()), manager(manager), playerInfo(playerInfo) {

    this->direction = playerInfo.getDirection();
	this->frameHead = 0;
    this->state = std::shared_ptr<CharacterState>(new StillState());
	setArmor(playerInfo.getBodyID());
	setHead(playerInfo.getHeadID());
	setHelmet(playerInfo.getHelmetID());
	setShield(playerInfo.getShieldID());
  setWeapon(playerInfo.getWeaponID());
}

void Player::render(Camera& camera) {
 	this->body->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y),int(this->direction));
  if (this->weapon != nullptr)
    this->weapon->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y),int(this->direction));
  if (this->shield != nullptr)
	  this->shield->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y),int(this->direction));
  if (this->head != nullptr)
    this->head->render(int(posX+4-camera.getCameraPosition().x), int((posY-this->body->getHeight()/2)-camera.getCameraPosition().y), this->frameHead);
  if (this->helmet != nullptr)
    this->helmet->render(int(posX+4-camera.getCameraPosition().x), int((posY-this->body->getHeight()/2)-camera.getCameraPosition().y), this->frameHead);
}

void Player::update(double dt) {
  if(this->state != nullptr && 
  (this->state->getState() == CharacterStateID::Move ||
   this->state->getState() == CharacterStateID::Dead)) {
    Point aux(posX, posY);
    this->center = aux;
    this->body->update(dt);
    if (this->weapon != nullptr)
      this->weapon->update(dt);
    if (this->shield != nullptr)
      this->shield->update(dt);
  }
}

void Player::setFrameHead() {
    switch (this->direction) {
      case Direction::down:
        this->frameHead = 0;
        break;
      case Direction::right:
        this->frameHead = 1;
        break;
      case Direction::left:
        this->frameHead = 2;
        break;
      case Direction::up:
        this->frameHead = 3;
        break;
    }
}

void Player::updatePlayerInfo(PlayerInfo info) {
  this->posX = info.getX();
  this->posY = info.getY();
  this->direction = info.getDirection();
  this->playerInfo = info;
  setState(info.getState());
  setArmor(info.getBodyID());
  setHead(info.getHeadID());
  setHelmet(info.getHelmetID());
	setShield(info.getShieldID());
  setWeapon(info.getWeaponID());
  setFrameHead();
}

InputInfo Player::dropItem(int itemNumber) {
  InputInfo info = this->state->dropItem(*this, itemNumber);
  return info;
}

InputInfo Player::selectItem(int itemNumber) {
  InputInfo info = this->state->selectItem(*this, itemNumber);
  return info;
}

InputInfo Player::handleEvent(SDL_Event& event, Camera& camera) {
  InputInfo input;
	if(event.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
            case SDLK_w:
                input = this->state->moveUp(*this);
                break;
            case SDLK_s:
                input = this->state->moveDown(*this);
                break;
            case SDLK_a:
                input = this->state->moveLeft(*this);
                break;
            case SDLK_d:
                input = this->state->moveRight(*this);
                break;
            case SDLK_r:
                input = this->state->resurrect(*this);
                break;
            case SDLK_g:
                break;
            case SDLK_b:
                break;
            case SDLK_v:
                break;
            case SDLK_t:
                input = this->state->takeItem(*this);
                break;
            case SDLK_h:
                input = this->state->cure(*this);
                break;
            case SDLK_y:
                input = this->state->meditate(*this);
                break;
            case SDLK_1:
                input = this->state->selectItem(*this, 1);
                break;
            case SDLK_2:
                input = this->state->selectItem(*this, 2);
                break;
            case SDLK_3:
                input = this->state->selectItem(*this, 3);
                break;
            case SDLK_4:
                input = this->state->selectItem(*this, 4);
                break;
            case SDLK_5:
                input = this->state->selectItem(*this, 5);
                break;
            case SDLK_6:
                input = this->state->selectItem(*this, 6);
                break;
            case SDLK_7:
                input = this->state->selectItem(*this, 7);
                break;
            case SDLK_8:
                input = this->state->selectItem(*this, 8);
                break;
            case SDLK_9:
                input = this->state->selectItem(*this, 9);
                break;
        }
    } else if (event.type == SDL_KEYUP) {
		switch(event.key.keysym.sym) {
		    case SDLK_w:
				input = this->state->stopMove(*this);
				break;
            case SDLK_s:
                input = this->state->stopMove(*this);
                break;
            case SDLK_a:
                input = this->state->stopMove(*this);
                break;
            case SDLK_d:
                  input = this->state->stopMove(*this);
                  break;
    }
	} else if (event.type == SDL_MOUSEBUTTONDOWN) {
          int x,y;
          SDL_GetMouseState(&x, &y);
          Point coord = camera.calculateGlobalPosition(Point(x,y));
          input = this->state->selectTarget(*this, coord);
  }
    return input;
}

void Player::setState(CharacterStateID newState) {
	if(this->state == nullptr || this->state->getState() != newState) {
		switch (newState) {
			case CharacterStateID::Still:
				this->state = std::shared_ptr<CharacterState>(new StillState());
				break;
			case CharacterStateID::Interact:
				this->state = std::shared_ptr<CharacterState>(new InteractState());
				break;
			case CharacterStateID::Move:
				this->state = std::shared_ptr<CharacterState>(new MoveState());
				break;
			case CharacterStateID::Dead:
				this->state = std::shared_ptr<CharacterState>(new DeadState());
				break;
            case CharacterStateID::Meditate:
                this->state = std::shared_ptr<CharacterState>(new MeditateState());
                break;
            case CharacterStateID::Attack:
                this->state = std::shared_ptr<CharacterState>(new AttackState());
                break;
		}
	}
}

void Player::setHead(HeadID head) {
	if (this->head == nullptr || head != this->head->getId()) {
	  switch (head) {
	      case HeadID::Nothing:
	          this->head = nullptr;
            break;
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
        case BodyID::Ghost:
            this->body = std::shared_ptr<Body>(new GhostBody(this->manager));
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

void Player::setWeapon(WeaponID newWeapon){
  if (this->weapon == nullptr || newWeapon != this->weapon->getId()){
      switch (newWeapon) {
    	case WeaponID::Nothing:
            this->weapon = nullptr;
            break;
        case WeaponID::Ax:
            this->weapon = std::shared_ptr<Weapon>(new Ax(this->manager));
            break;
        case WeaponID::AshStick:
            this->weapon = std::shared_ptr<Weapon>(new AshStick(this->manager));
            break;
        case WeaponID::GnarledStick:
            this->weapon = std::shared_ptr<Weapon>(new GnarledStick(this->manager));
            break;
        case WeaponID::SimpleArc:
            this->weapon = std::shared_ptr<Weapon>(new SimpleArc(this->manager));
            break;
        case WeaponID::CompoundArc:
            this->weapon = std::shared_ptr<Weapon>(new CompoundArc(this->manager));
            break;
        case WeaponID::LongSword:
            this->weapon = std::shared_ptr<Weapon>(new LongSword(this->manager));
            break;
        case WeaponID::Hammer:
            this->weapon = std::shared_ptr<Weapon>(new Hammer(this->manager));
            break;
        case WeaponID::Crosier:
            this->weapon = std::shared_ptr<Weapon>(new Crosier(this->manager));
            break;
        case WeaponID::ElficFlaute:
            this->weapon = std::shared_ptr<Weapon>(new ElficFlaute(this->manager));
            break;
		}
	}
}

Point* Player::getCenter() {
	return &center;
}

uint Player::getLevel() {
  return this->playerInfo.getLevel();
}

uint Player::getHealth() {
  return this->playerInfo.getLife();
}

uint Player::getMana() {
  return this->playerInfo.getMana();
}

uint Player::getGold() {
  return this->playerInfo.getGoldAmount();
}

uint Player::getMaxHealth() {
  return this->playerInfo.getMaxLife();
}

uint Player::getMaxMana() {
  return this->playerInfo.getMaxMana();
}

uint Player::getSafeGold() {
  return this->playerInfo.getSafeGold();
}

uint Player::getExp() {
  return this->playerInfo.getExp();
}

uint Player::getMaxExp() {
  return this->playerInfo.getMaxExp();
}

std::string Player::getInventory() {
  return this->playerInfo.getInventory();
}

CharacterStateID& Player::getState() {
  return this->state->getState();
}

PlayerInfo Player::getInfo() {
  return this->playerInfo;
}

Player::~Player()= default;