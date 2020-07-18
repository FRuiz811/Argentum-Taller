#include "Player.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "characterStates/StillState.h"
#include "characterStates/MoveState.h"
#include "characterStates/MeditateState.h"
#include "characterStates/InteractState.h"
#include "characterStates/AttackState.h"
#include "Items/Animation.h"
#include "Items/MeditateAnimation.h"


Player::Player(const TextureManager& manager, const PlayerInfo& playerInfo,
  const MusicManager& mixer) : Character(playerInfo.getX(),playerInfo.getY(),
  playerInfo.getId(),manager,mixer), center(playerInfo.getX(),playerInfo.getY()),
   playerInfo(playerInfo){

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
  Character::render(camera);
  playEffectLowLife();
}


void Player::update(double dt) {
  if(this->state != nullptr &&
  this->state->getState() == CharacterStateID::Move) {
    Point aux(posX, posY);
    this->center = aux;
    this->body->update(dt,direction);
    if (this->weapon != nullptr)
      this->weapon->update(dt,direction);
    if (this->shield != nullptr)
      this->shield->update(dt,direction);
  }
  if (this->animation != nullptr)
    this->animation->update();
}

void Player::updatePlayerInfo(const PlayerInfo& info) {
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
  setAnimation(info.getAttackWeapon());
}

void Player::playEffectLowLife() {
  if(this->playerInfo.getLife() < this->playerInfo.getMaxLife()*0.1 &&
    this->playerInfo.getLife() != 0 && playLowLife) {
    const Effect& effect = mixer.getEffect(MusicID::Heart);
    effect.playEffect(-1);
    playLowLife = false;
  } else if (this->playerInfo.getLife() >= this->playerInfo.getMaxLife()*0.1 &&
   !playLowLife && this->playerInfo.getLife() == 0) {
    const Effect& effect = mixer.getEffect(MusicID::Heart);
    effect.pause();
    playLowLife = true;
  }
}

InputInfo Player::dropItem(int itemNumber) {
  InputInfo info = this->state->dropItem(*this, itemNumber);
  return info;
}

InputInfo Player::selectItem(int itemNumber) {
  InputInfo info = this->state->selectItem(*this, itemNumber);
  return info;
}

InputInfo Player::resurrect() {
  InputInfo info = this->state->resurrect(*this);
  return info;
}

InputInfo Player::cure() {
  InputInfo info = this->state->cure(*this);
  return info;
}

InputInfo Player::buy(int itemNumber) {
  InputInfo info = this->state->buyItem(*this,itemNumber);
  return info;
}

InputInfo Player::deposit(int information, bool isItem) {
  InputInfo info = this->state->deposit(*this,information,isItem);
  return info;
}

InputInfo Player::retire(int information, bool isItem) {
  InputInfo info = this->state->retire(*this,information,isItem);
  return info;
}

InputInfo Player::sell(int itemNumber) {
  InputInfo info = this->state->sellItem(*this,itemNumber);
  return info;
}

InputInfo Player::unequipItem(int itemNumber) {
  InputInfo info = this->state->unequipItem(*this,itemNumber);
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
            case SDLK_q:
                input = this->state->takeItem(*this);
                break;
            case SDLK_h:
                input = this->state->cure(*this);
                break;
            case SDLK_e:
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
          if (camera.clickInMap(Point(x,y))){
            Point coord = camera.calculateGlobalPosition(Point(x,y));
            input = this->state->selectTarget(*this, coord);
          }
  }
    return input;
}

void Player::setState(CharacterStateID newState) {
  if(this->state != nullptr && 
     this->state->getState() == CharacterStateID::Meditate &&
     newState != CharacterStateID::Meditate)
     this->animation = nullptr;
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
      case CharacterStateID::Meditate:
        this->state = std::shared_ptr<CharacterState>(new MeditateState());
        this->animation = std::shared_ptr<Animation>(new MeditateAnimation(this->manager,mixer.getEffect(MusicID::Meditation)));
        break;
      case CharacterStateID::Attack:
        this->state = std::shared_ptr<CharacterState>(new AttackState());
        break;
		}
	}
}

Point* Player::getCenter() {
	return &center;
}

uint Player::getLevel() const {
  return this->playerInfo.getLevel();
}

uint Player::getHealth() const {
  return this->playerInfo.getLife();
}

uint Player::getMana() const{
  return this->playerInfo.getMana();
}

uint Player::getGold() const {
  return this->playerInfo.getGoldAmount();
}

uint Player::getMaxHealth() const {
  return this->playerInfo.getMaxLife();
}

uint Player::getMaxMana()const {
  return this->playerInfo.getMaxMana();
}

uint Player::getSafeGold() const {
  return this->playerInfo.getSafeGold();
}

uint Player::getExp() const {
  return this->playerInfo.getExp();
}

uint Player::getMaxExp() const {
  return this->playerInfo.getMaxExp();
}

std::string Player::getInventory() const {
  return this->playerInfo.getInventory();
}

CharacterStateID& Player::getState() const {
  return this->state->getState();
}

PlayerInfo Player::getInfo() const {
  return this->playerInfo;
}

Player::~Player()= default;