#include "NPC.h"

#include <memory>
#include "Items/ElfHead.h"
#include "Items/HumanHead.h"
#include "Items/DwarfHead.h"
#include "Items/GnomeHead.h"
#include "Items/ZombieHead.h"
#include "Items/PriestHead.h"
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
#include "Items/BankerBody.h"
#include "Items/MerchantBody.h"
#include "Items/SkeletonBody.h"
#include "Items/SpiderBody.h"
#include "Items/GoblinBody.h"
#include "Items/PriestBody.h"
#include "Items/ZombieBody.h"
#include "Items/Ax.h"
#include "Items/AshStick.h"
#include "Items/Crosier.h"
#include "Items/ElficFlaute.h"
#include "Items/SimpleArc.h"
#include "Items/CompoundArc.h"
#include "Items/LongSword.h"
#include "Items/Hammer.h"
#include "Items/GnarledStick.h"
#include "Items/HitAnimation.h"
#include "Items/MagicArrowAnimation.h"
#include "Items/ExplotionAnimation.h"
#include "Items/MissileAnimation.h"
#include "Items/MeditateAnimation.h"
#include "Items/CureAnimation.h"
#include "characterStates/StillState.h"
#include "characterStates/MoveState.h"
#include "characterStates/MeditateState.h"
#include "characterStates/InteractState.h"
#include "characterStates/AttackState.h"
#include "../common/Random.h"

NPC::NPC(const TextureManager& manager, const GameObjectInfo& gameObjectInfo, 
  const MusicManager& mixer): Character(gameObjectInfo.getX(), gameObjectInfo.getY(),
  gameObjectInfo.getId()), manager(manager), mixer(mixer){
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
    if(distance < 800){
      if (this->body != nullptr)
      this->body->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y));
      if (this->head != nullptr)
          this->head->render(int(posX+4-camera.getCameraPosition().x), int((posY-this->body->getHeight()/2)-camera.getCameraPosition().y));
      if (this->weapon != nullptr)
          this->weapon->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y));
      if (this->shield != nullptr)
        this->shield->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y));
      if (this->helmet != nullptr)
          this->helmet->render(int(posX+4-camera.getCameraPosition().x), int((posY-this->body->getHeight()/2)-camera.getCameraPosition().y));
      if (this->animation != nullptr)
          this->animation->render(int(posX-camera.getCameraPosition().x), int(posY-camera.getCameraPosition().y));
      MusicID effectId = selectSound();
      if (Random::get(0,500) == 1 && effectId != MusicID::Nothing) {
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

void NPC::setFrameHead() {
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
    if (this->head != nullptr)
      this->head->update(this->frameHead);
    if (this->helmet != nullptr)
      this->helmet->update(this->frameHead);
}

void NPC::setHead(HeadID head) {
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
        case HeadID::Priest:
            this->head = std::shared_ptr<Head>(new PriestHead(this->manager));
            break;
        case HeadID::Zombie:
            this->head = std::shared_ptr<Head>(new ZombieHead(this->manager));
            break;
    }
  }
}

void NPC::setArmor(BodyID newArmor) {
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
        case BodyID::Goblin:
            this->body = std::shared_ptr<Body>(new GoblinBody(this->manager));
            break;
        case BodyID::Skeleton:
            this->body = std::shared_ptr<Body>(new SkeletonBody(this->manager));
            break;
        case BodyID::Spider:
            this->body = std::shared_ptr<Body>(new SpiderBody(this->manager));
            break;
        case BodyID::Zombie:
            this->body = std::shared_ptr<Body>(new ZombieBody(this->manager));
            break;
        case BodyID::Priest:
            this->body = std::shared_ptr<Body>(new PriestBody(this->manager));
            break;
        case BodyID::Merchant:
            this->body = std::shared_ptr<Body>(new MerchantBody(this->manager));
            break;
        case BodyID::Banker:
            this->body = std::shared_ptr<Body>(new BankerBody(this->manager));
            break;
        case BodyID::Nothing:
            this->body = nullptr;
            break;
    }
    if (this->body != nullptr)
      this->body->update(0,direction);
  }
}

void NPC::setHelmet(HelmetID newHelmet) {
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

void NPC::setShield(ShieldID newShield) {
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
    if (this->shield != nullptr)
     this->shield->update(0,direction);
	}
}

void NPC::setWeapon(WeaponID newWeapon){
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
    if (this->weapon != nullptr)
      this->weapon->update(0,direction);
	}
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
		}
	}
}

void NPC::setAnimation(WeaponID weaponEnemy) {
  if (this->animation == nullptr || this->animation->finished()){
      switch (weaponEnemy) {
    	case WeaponID::Nothing:
            this->animation = nullptr;
            break;
        case WeaponID::Ax:
            this->animation = std::shared_ptr<Animation>(new HitAnimation(this->manager,mixer.getEffect(MusicID::Ax)));
            break;
        case WeaponID::AshStick:
            this->animation = std::shared_ptr<Animation>(new MagicArrowAnimation(this->manager,mixer.getEffect(MusicID::MagicArrow)));
            break;
        case WeaponID::GnarledStick:
            this->animation = std::shared_ptr<Animation>(new MissileAnimation(this->manager,mixer.getEffect(MusicID::Misil)));
            break;
        case WeaponID::SimpleArc:
            this->animation = std::shared_ptr<Animation>(new HitAnimation(this->manager,mixer.getEffect(MusicID::Arrow)));
            break;
        case WeaponID::CompoundArc:
            this->animation = std::shared_ptr<Animation>(new HitAnimation(this->manager,mixer.getEffect(MusicID::Arrow)));
            break;
        case WeaponID::LongSword:
            this->animation = std::shared_ptr<Animation>(new HitAnimation(this->manager,mixer.getEffect(MusicID::Sword)));
            break;
        case WeaponID::Hammer:
            this->animation = std::shared_ptr<Animation>(new HitAnimation(this->manager,mixer.getEffect(MusicID::Hammer)));
            break;
        case WeaponID::Crosier:
            this->animation = std::shared_ptr<Animation>(new ExplotionAnimation(this->manager,mixer.getEffect(MusicID::Explotion)));
            break;
        case WeaponID::ElficFlaute:
            this->animation = std::shared_ptr<Animation>(new CureAnimation(this->manager,mixer.getEffect(MusicID::Cure)));
            break;
      }
		}
}

CharacterStateID& NPC::getState() {
  return this->state->getState();
}

NPC::~NPC()= default;