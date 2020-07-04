#include "NPC.h"
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

NPC::NPC(const TextureManager& manager, const GameObjectInfo& gameObjectInfo):
  Character(gameObjectInfo.getX(), gameObjectInfo.getY(), gameObjectInfo.getId()), manager(manager){
    this->direction = gameObjectInfo.getDirection();
    this->frameHead = 0;
    setArmor(gameObjectInfo.getBodyID());
    setHead(gameObjectInfo.getHeadID());
    setHelmet(gameObjectInfo.getHelmetID());
    setShield(gameObjectInfo.getShieldID());
    setWeapon(gameObjectInfo.getWeaponID());
}

void NPC::render(Camera& camera) {
    if (this->body != nullptr)
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

void NPC::update(double dt) {
    if(this->body !=nullptr)
    	this->body->update(dt);
    if (this->weapon != nullptr)
        this->weapon->update(dt);
    if (this->shield != nullptr)
        this->shield->update(dt);
}

void NPC::updatePlayerInfo(const GameObjectInfo &info) {
    this->posX = info.getX();
    this->posY = info.getY();
    this->direction = info.getDirection();
    setFrameHead();
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
	}
}

NPC::~NPC()= default;