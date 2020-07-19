#include "NPC.h"

#include <memory>
#include "characterStates/StillState.h"
#include "characterStates/MoveState.h"
#include "characterStates/MeditateState.h"
#include "characterStates/InteractState.h"
#include "characterStates/AttackState.h"
#include "characterStates/ResurrectState.h"
#include "../common/Random.h"
#include "Items/Animation.h"
#include "Items/MeditateAnimation.h"

NPC::NPC(const TextureManager& manager, const GameObjectInfo& gameObjectInfo, 
  const MusicManager& mixer): Character(gameObjectInfo.getX(), gameObjectInfo.getY(),
  gameObjectInfo.getId(),manager,mixer){
    this->direction = gameObjectInfo.getDirection();
    setState(gameObjectInfo.getState());
    setFrameHead();
    setArmor(gameObjectInfo.getBodyID());
    setHead(gameObjectInfo.getHeadID());
    setHelmet(gameObjectInfo.getHelmetID());
    setShield(gameObjectInfo.getShieldID());
    setWeapon(gameObjectInfo.getWeaponID());
}

void NPC::render(Camera& camera) {
  if (!aItem) {
    int distance = camera.distanceFromTarget(this->getPosition());
    Character::render(camera);
    if(distance < 400){
      MusicID effectId = selectSound();
      if (Random::get(0,600) == 1 && effectId != MusicID::Nothing) {
        const Effect& effect = mixer.getEffect(effectId);
        if (distance > 255)
          distance = 255;
        effect.setDistance(distance);
        effect.playEffect(0,64);
      }
    }
  } else {
    if (this->item != nullptr)
      this->item->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y));
  }
}

void NPC::update(double dt) {
  if(this->state != nullptr && this->state->getState() == CharacterStateID::Move) {
    if(this->body !=nullptr)
    	this->body->update(dt,direction);
    if (this->weapon != nullptr)
        this->weapon->update(dt,direction);
    if (this->shield != nullptr)
        this->shield->update(dt,direction);
  }
  if (this->animation != nullptr)
    this->animation->update();
}

void NPC::updatePlayerInfo(const GameObjectInfo &info) {
    this->posX = info.getX();
    this->posY = info.getY();
    this->direction = info.getDirection();
    setState(info.getState());
    setArmor(info.getBodyID());
    setHead(info.getHeadID());
    setHelmet(info.getHelmetID());
    setShield(info.getShieldID());
    setWeapon(info.getWeaponID());
    setFrameHead();
    setAnimation(info.getAttackWeapon());
    if (info.isItem())
      setItem(info.getItemID());
}

bool NPC::isItem() const {
  return this->aItem;
}

void NPC::setItem(ItemsInventoryID itemId) {
  this->aItem = true;
  this->item = std::make_shared<Item>(manager.getTexture(itemId),32,32);
}

MusicID NPC::selectSound() {
  MusicID effectId = MusicID::Nothing;
  if (body != nullptr) {
      switch (this->body->getId()) {
          case BodyID::Goblin:
              effectId = MusicID::Goblin;
              break;
          case BodyID::Skeleton:
              effectId = MusicID::Skeleton;
              break;
          case BodyID::Zombie:
              effectId = MusicID::Zombie;
              break;
          default:
              effectId = MusicID::Nothing;
      }
  }
  return effectId;
}

void NPC::setState(CharacterStateID newState) {
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
      case CharacterStateID::Resurrect:
        this->state = std::shared_ptr<CharacterState>(new ResurrectState());
        break;
		}
	}
}

CharacterStateID& NPC::getState() const {
  return this->state->getState();
}

NPC::~NPC()= default;