#include "ItemTranslator.h"

ItemTranslator::ItemTranslator() = default;

ItemsInventoryID ItemTranslator::weaponToItem(WeaponID weapon){
    ItemsInventoryID idItem = ItemsInventoryID::Nothing;
    switch(weapon) {
		case WeaponID::SimpleArc:
			idItem = ItemsInventoryID::SimpleArc;
			break;
		case WeaponID::CompoundArc:
			idItem = ItemsInventoryID::CompoundArc;
			break;
		case WeaponID::LongSword:
			idItem = ItemsInventoryID::LongSword;
			break;
		case WeaponID::Hammer:
			idItem = ItemsInventoryID::Hammer;
			break;
		case WeaponID::Ax:
			idItem = ItemsInventoryID::Ax;
			break;
		case WeaponID::ElficFlaute:
			idItem = ItemsInventoryID::ElficFlaute;
			break;
		case WeaponID::AshStick:
			idItem = ItemsInventoryID::AshStick;
			break;
		case WeaponID::Crosier:
			idItem = ItemsInventoryID::Crosier;
			break;
		case WeaponID::GnarledStick:
			idItem = ItemsInventoryID::GnarledStick;
			break;
		case WeaponID::Nothing:
			idItem = ItemsInventoryID::Nothing;
			break;
	}
    return idItem;
}

ItemsInventoryID ItemTranslator::bodyToItem(BodyID body){
    ItemsInventoryID idItem = ItemsInventoryID::Nothing;
    switch(body) {
		case BodyID::BlueCommon:
			idItem = ItemsInventoryID::BlueCommon;
			break;
		case BodyID::GreenCommon:
			idItem = ItemsInventoryID::GreenCommon;
			break;
		case BodyID::RedCommon:
			idItem = ItemsInventoryID::RedCommon;
			break;
		case BodyID::LeatherArmor:
			idItem = ItemsInventoryID::LeatherArmor;
			break;
		case BodyID::BlueTunic:
			idItem = ItemsInventoryID::BlueTunic;
			break;
		case BodyID::PlateArmor:
			idItem = ItemsInventoryID::PlateArmor;
			break;
		default:
			idItem = ItemsInventoryID::Nothing;
			break;
    }
    return idItem;
}

ItemsInventoryID ItemTranslator::helmetToItem(HelmetID helmet){
    ItemsInventoryID idItem = ItemsInventoryID::Nothing;
    switch(helmet) {
		case HelmetID::Hood:
			idItem = ItemsInventoryID::Hood;
			break;
		case HelmetID::MagicHat:
			idItem = ItemsInventoryID::MagicHat;
			break;
		case HelmetID::IronHelmet:
			idItem = ItemsInventoryID::IronHelmet;
			break;
		case HelmetID::Nothing:
			idItem = ItemsInventoryID::Nothing;
			break;
		default:
			idItem = ItemsInventoryID::Nothing;
			break;
	}
    return idItem;
}

ItemsInventoryID ItemTranslator::shieldToItem(ShieldID shield){
    ItemsInventoryID idItem = ItemsInventoryID::Nothing;
	switch(shield) {
		case ShieldID::IronShield:
			idItem = ItemsInventoryID::IronShield;
			break;
		case ShieldID::TurtleShield:
			idItem = ItemsInventoryID::TurtleShield;
			break;
		case ShieldID::Nothing:
			idItem = ItemsInventoryID::Nothing;
			break;
	}
    return idItem;
}

WeaponID ItemTranslator::itemToWeapon(ItemsInventoryID item){
    WeaponID weapon;
    switch(item) {
		case ItemsInventoryID::SimpleArc:
			weapon = WeaponID::SimpleArc;
			break;
		case ItemsInventoryID::CompoundArc:
			weapon = WeaponID::CompoundArc;
			break;
		case ItemsInventoryID::LongSword:
			weapon = WeaponID::LongSword;
			break;
		case ItemsInventoryID::Hammer:
			weapon = WeaponID::Hammer;
			break;
		case ItemsInventoryID::Ax:
			weapon = WeaponID::Ax;
			break;
		case ItemsInventoryID::ElficFlaute:
			weapon = WeaponID::ElficFlaute;
			break;
		case ItemsInventoryID::AshStick:
			weapon = WeaponID::AshStick;
			break;
		case ItemsInventoryID::Crosier:
			weapon = WeaponID::Crosier;
			break;
		case ItemsInventoryID::GnarledStick:
			weapon = WeaponID::GnarledStick;
			break;
        default:
            weapon = WeaponID::Nothing;
    }
    return weapon;
}

ShieldID ItemTranslator::itemToShield(ItemsInventoryID item){
    ShieldID shield = ShieldID::Nothing;
    switch (item) {
        case ItemsInventoryID::IronShield:
			shield = ShieldID::IronShield;
			break;
		case ItemsInventoryID::TurtleShield:
			shield = ShieldID::TurtleShield;
			break;
        default:
            shield = ShieldID::Nothing;
    }
    return shield;
}

BodyID ItemTranslator::itemToBody(ItemsInventoryID item){
    BodyID body = BodyID::Nothing;
    switch (item) {
        case ItemsInventoryID::BlueCommon:
			body = BodyID::BlueCommon;
			break;
		case ItemsInventoryID::GreenCommon:
			body = BodyID::GreenCommon;
			break;
		case ItemsInventoryID::RedCommon:
			body = BodyID::RedCommon;
			break;
		case ItemsInventoryID::LeatherArmor:
			body = BodyID::LeatherArmor;
			break;
		case ItemsInventoryID::BlueTunic:
			body = BodyID::BlueTunic;
			break;
		case ItemsInventoryID::PlateArmor:
			body = BodyID::PlateArmor;
			break;
		default:
			body = BodyID::Nothing;
			break;
    }
    return body;
}
    
HelmetID ItemTranslator::itemToHelmet(ItemsInventoryID item){
    HelmetID helmet = HelmetID::Nothing;
    switch (item) {
        case ItemsInventoryID::Hood:
			helmet = HelmetID::Hood;
			break;
		case ItemsInventoryID::MagicHat:
			helmet = HelmetID::MagicHat;
			break;
		case ItemsInventoryID::IronHelmet:
			helmet = HelmetID::IronHelmet;
			break;
        case ItemsInventoryID::Nothing:
            helmet = HelmetID::Nothing;
            break;
		default:
			helmet = HelmetID::Nothing;
			break;
    }
    return helmet;
}

ItemTranslator::~ItemTranslator() = default;
