#include "TextureManager.h"
#include <utility>

TextureManager::TextureManager(SDL_Renderer& renderer) : textures(),
	renderer(renderer) {}

void TextureManager::createTexture(TextureID id, const std::string& path) {
	Texture newTexture(path, this->renderer);
	this->textures.insert(std::make_pair(id, std::move(newTexture)));
}

void TextureManager::createTexture(TextureID id, const std::string& path, SDL_Color color) {
	Texture newTexture(path, this->renderer, color);
	this->textures.insert(std::make_pair(id, std::move(newTexture)));
}

void TextureManager::dropTexture(TextureID id) {
	this->textures.erase(id);
}

const Texture& TextureManager::getTexture(TextureID id) const {
	return this->textures.at(id);
}

const Texture& TextureManager::getTexture(BodyID id) const {
	TextureID idItem = TextureID::ItemNothing;
	switch(id) {
		case BodyID::BlueCommon:
			idItem = TextureID::ItemBlueCommonBody;
			break;
		case BodyID::GreenCommon:
			idItem = TextureID::ItemGreenCommonBody;
			break;
		case BodyID::RedCommon:
			idItem = TextureID::ItemRedCommonBody;
			break;
		case BodyID::LeatherArmor:
			idItem = TextureID::ItemLeatherArmor;
			break;
		case BodyID::BlueTunic:
			idItem = TextureID::ItemBlueTunic;
			break;
		case BodyID::PlateArmor:
			idItem = TextureID::ItemPlateArmor;
			break;
		case BodyID::Ghost:
			idItem = TextureID::ItemNothing;
			break;
		default:
			idItem = TextureID::ItemNothing;
			break;
	}
	const Texture& texture = getTexture(idItem);
	return texture;
}

const Texture& TextureManager::getTexture(HeadID id) const {
	TextureID idItem = TextureID::ItemNothing;
	switch(id) {
		case HeadID::Elf:
			idItem = TextureID::ElfHead;
			break;
		case HeadID::Gnome:
			idItem = TextureID::GnomeHead;
			break;
		case HeadID::Human:
			idItem = TextureID::HumanHead;
			break;
		case HeadID::Dwarf:
			idItem = TextureID::DwarfHead;
			break;
		case HeadID::Nothing:
			idItem = TextureID::ItemNothing;
			break;
		default:
			idItem = TextureID::ItemNothing;
			break;
	}
	const Texture& texture = getTexture(idItem);
	return texture;
}

const Texture& TextureManager::getTexture(HelmetID id) const {
	TextureID idItem = TextureID::ItemNothing;
	switch(id) {
		case HelmetID::Hood:
			idItem = TextureID::ItemHood;
			break;
		case HelmetID::MagicHat:
			idItem = TextureID::ItemMagicHat;
			break;
		case HelmetID::IronHelmet:
			idItem = TextureID::ItemIronHelmet;
			break;
		case HelmetID::Nothing:
			idItem = TextureID::ItemNothing;
			break;
		default:
			idItem = TextureID::ItemNothing;
			break;
	}
	const Texture& texture = getTexture(idItem);
	return texture;
}

const Texture& TextureManager::getTexture(WeaponID id) const {
	TextureID idItem = TextureID::ItemNothing;
	switch(id) {
		case WeaponID::SimpleArc:
			idItem = TextureID::ItemSimpleArc;
			break;
		case WeaponID::CompoundArc:
			idItem = TextureID::ItemCompoundArc;
			break;
		case WeaponID::LongSword:
			idItem = TextureID::ItemLongSword;
			break;
		case WeaponID::Hammer:
			idItem = TextureID::ItemHammer;
			break;
		case WeaponID::Ax:
			idItem = TextureID::ItemAx;
			break;
		case WeaponID::ElficFlaute:
			idItem = TextureID::ItemElficFlaute;
			break;
		case WeaponID::AshStick:
			idItem = TextureID::ItemAshStick;
			break;
		case WeaponID::Crosier:
			idItem = TextureID::ItemCrosier;
			break;
		case WeaponID::GnarledStick:
			idItem = TextureID::ItemGnarledStick;
			break;
		case WeaponID::Nothing:
			idItem = TextureID::ItemNothing;
			break;
		default:
			idItem = TextureID::ItemNothing;
			break;
	}
	const Texture& texture = getTexture(idItem);
	return texture;
}

const Texture& TextureManager::getTexture(ShieldID id) const {
	TextureID idItem = TextureID::ItemNothing;
	switch(id) {
		case ShieldID::IronShield:
			idItem = TextureID::ItemIronShield;
			break;
		case ShieldID::TurtleShield:
			idItem = TextureID::ItemTurtleShield;
			break;
		case ShieldID::Nothing:
			idItem = TextureID::ItemNothing;
			break;
	}
	const Texture& texture = getTexture(idItem);
	return texture;
}

const Texture& TextureManager::getTexture(ItemsInventoryID id) const {
	TextureID idText = TextureID::ItemNothing;
	switch(id) {
		case ItemsInventoryID::SimpleArc:
			idText = TextureID::ItemSimpleArc;
			break;
		case ItemsInventoryID::CompoundArc:
			idText = TextureID::ItemCompoundArc;
			break;
		case ItemsInventoryID::LongSword:
			idText = TextureID::ItemLongSword;
			break;
		case ItemsInventoryID::Hammer:
			idText = TextureID::ItemHammer;
			break;
		case ItemsInventoryID::Ax:
			idText = TextureID::ItemAx;
			break;
		case ItemsInventoryID::ElficFlaute:
			idText = TextureID::ItemElficFlaute;
			break;
		case ItemsInventoryID::AshStick:
			idText = TextureID::ItemAshStick;
			break;
		case ItemsInventoryID::Crosier:
			idText = TextureID::ItemCrosier;
			break;
		case ItemsInventoryID::GnarledStick:
			idText = TextureID::ItemGnarledStick;
			break;
		case ItemsInventoryID::IronShield:
			idText = TextureID::ItemIronShield;
			break;
		case ItemsInventoryID::TurtleShield:
			idText = TextureID::ItemTurtleShield;
			break;
		case ItemsInventoryID::Hood:
			idText = TextureID::ItemHood;
			break;
		case ItemsInventoryID::MagicHat:
			idText = TextureID::ItemMagicHat;
			break;
		case ItemsInventoryID::IronHelmet:
			idText = TextureID::ItemIronHelmet;
			break;
		case ItemsInventoryID::BlueCommon:
			idText = TextureID::ItemBlueCommonBody;
			break;
		case ItemsInventoryID::GreenCommon:
			idText = TextureID::ItemGreenCommonBody;
			break;
		case ItemsInventoryID::RedCommon:
			idText = TextureID::ItemRedCommonBody;
			break;
		case ItemsInventoryID::LeatherArmor:
			idText = TextureID::ItemLeatherArmor;
			break;
		case ItemsInventoryID::BlueTunic:
			idText = TextureID::ItemBlueTunic;
			break;
		case ItemsInventoryID::PlateArmor:
			idText = TextureID::ItemPlateArmor;
			break;
		case ItemsInventoryID::HealthPotion:
			idText = TextureID::HealthPotion;
			break;
		case ItemsInventoryID::ManaPotion:
			idText = TextureID::ManaPotion;
			break;
        case ItemsInventoryID::Gold:
            idText = TextureID::Gold;
            break;
		case ItemsInventoryID::Nothing:
			idText = TextureID::ItemNothing;
			break;
		default:
			idText = TextureID::ItemNothing;
			break;
    }
	const Texture& texture = getTexture(idText);
	return texture;
}

void TextureManager::loadTextures() {
	SDL_Color textColor = {0x0, 0x0, 0x0};
	createTexture(TextureID::PresentationImage, "assets/img/ImagenPresentacion.jpg");
	createTexture(TextureID::LobbyBackground, "assets/img/Fondo Inicio.jpg");
	createTexture(TextureID::ZombieHead, "assets/img/Zombie Cabeza.png",textColor);
	createTexture(TextureID::ElfHead,"assets/img/Cabeza Elfo.png", textColor);
	createTexture(TextureID::HumanHead, "assets/img/Cabeza Humano.png",textColor);
	createTexture(TextureID::DwarfHead, "assets/img/Cabeza Enano.png",textColor);
	createTexture(TextureID::GnomeHead, "assets/img/Cabeza Gnomo.png",textColor);
	createTexture(TextureID::PriestHead,"assets/img/Sacerdote Cabeza Sprite.png", textColor);
	createTexture(TextureID::ZombieBody, "assets/img/Zombie Cuerpo Sprite.png",textColor);
	createTexture(TextureID::BlueTunic,"assets/img/Tunica Azul Sprite.png", textColor);
	createTexture(TextureID::PriestBody, "assets/img/Sacerdote Sprite.png",textColor);
	createTexture(TextureID::LeatherArmor, "assets/img/Armadura de Cuero Sprite.png",textColor);
	createTexture(TextureID::PlateArmor, "assets/img/Armadura de Placas Sprite.png",textColor);
	createTexture(TextureID::BlueCommonBody, "assets/img/Vestimenta Comun azul Sprite.png",textColor);
	createTexture(TextureID::GreenCommonBody, "assets/img/Vestimenta Comun verde Sprite.png",textColor);
	createTexture(TextureID::RedCommonBody, "assets/img/Vestimenta Comun roja Sprite.png",textColor);
	createTexture(TextureID::TurtleShield, "assets/img/Escudo de Tortuga Sprite.png",textColor);
	createTexture(TextureID::IronShield, "assets/img/Escudo de Hierro Sprite.png",textColor);
	createTexture(TextureID::IronHelmet, "assets/img/Casco de Hierro Sprite.png", textColor);
	createTexture(TextureID::Hood, "assets/img/Capucha Sprite.png",textColor);
	createTexture(TextureID::MagicHat, "assets/img/Sombrero Magico Sprite.png", textColor);
	createTexture(TextureID::AshStick, "assets/img/Vara de Fresno Sprite.png", textColor);
	createTexture(TextureID::LongSword, "assets/img/Espada Larga Sprite.png", textColor);
	createTexture(TextureID::Hammer, "assets/img/Martillo Sprite.png", textColor);
	createTexture(TextureID::SimpleArc, "assets/img/Arco Simple Sprite.png", textColor);
	createTexture(TextureID::CompoundArc, "assets/img/Arco Compuesto Sprite.png", textColor);
	createTexture(TextureID::GnarledStick, "assets/img/Baston Nudoso Sprite.png", textColor);
	createTexture(TextureID::Crosier, "assets/img/Baculo Engarzado Sprite.png", textColor);
	createTexture(TextureID::Ax, "assets/img/Hacha Sprite.png", textColor);
	createTexture(TextureID::ElficFlaute, "assets/img/Flauta Elfica Sprite.png", textColor);
	createTexture(TextureID::Spider, "assets/img/Araña Sprite.png",textColor);
	createTexture(TextureID::Skeleton, "assets/img/Esqueleto Sprite.png", textColor);
	createTexture(TextureID::Banker, "assets/img/Banquero Sprite.png", textColor);
	createTexture(TextureID::Merchant, "assets/img/Comerciante Sprite.png", textColor);
	createTexture(TextureID::Goblin, "assets/img/Goblin.png", textColor);
	createTexture(TextureID::Ghost, "assets/img/Fantasma Sprite.png", textColor);
	createTexture(TextureID::ManaPotion, "assets/img/Pocion Mana.png", textColor);
	createTexture(TextureID::HealthPotion, "assets/img/Pocion Vida.png", textColor);
	createTexture(TextureID::Gold, "assets/img/Oro.png", textColor);
	createTexture(TextureID::ItemHood, "assets/img/Capucha.png", textColor);
	createTexture(TextureID::ItemIronHelmet, "assets/img/Casco de Hierro.png", textColor);
	createTexture(TextureID::ItemMagicHat, "assets/img/Sombrero Magico.png", textColor);
	createTexture(TextureID::ItemIronShield, "assets/img/Escudo de Hierro.png", textColor);
	createTexture(TextureID::ItemTurtleShield, "assets/img/Escudo de Tortuga.png", textColor);
	createTexture(TextureID::ItemAx, "assets/img/Hacha.png", textColor);
	createTexture(TextureID::ItemSimpleArc, "assets/img/Arco Simple.png", textColor);
	createTexture(TextureID::ItemCompoundArc, "assets/img/Arco Compuesto.png", textColor);
	createTexture(TextureID::ItemHammer, "assets/img/Martillo.png", textColor);
	createTexture(TextureID::ItemLongSword, "assets/img/Espada Larga.png", textColor);
	createTexture(TextureID::ItemAshStick, "assets/img/Vara de Fresno.png", textColor);
	createTexture(TextureID::ItemCrosier, "assets/img/Baculo Engarzado.png", textColor);
	createTexture(TextureID::ItemGnarledStick, "assets/img/Baston Nudoso.png", textColor);
	createTexture(TextureID::ItemElficFlaute, "assets/img/Flauta Elfica.png", textColor);
	createTexture(TextureID::ItemGreenCommonBody, "assets/img/Vestimenta Comun verde.png", textColor);
	createTexture(TextureID::ItemBlueCommonBody, "assets/img/Vestimenta Comun azul.png", textColor);
	createTexture(TextureID::ItemRedCommonBody, "assets/img/Vestimenta Comun roja.png", textColor);
	createTexture(TextureID::ItemBlueTunic, "assets/img/Tunica Azul.png", textColor);
	createTexture(TextureID::ItemLeatherArmor, "assets/img/Armadura de Cuero.png", textColor);
	createTexture(TextureID::ItemPlateArmor, "assets/img/Armadura de Placas.png", textColor);
	createTexture(TextureID::TopBar, "assets/img/Fondo Barra Superior.jpg");
	createTexture(TextureID::Star, "assets/img/Estrella.jpg", textColor);
	createTexture(TextureID::StatsBackground, "assets/img/StatsBackground.jpg");
	createTexture(TextureID::ItemNothing, "assets/img/RecuadroItems.jpg");
	createTexture(TextureID::MeditateEffect, "assets/img/Efecto Meditar.png", textColor);
	createTexture(TextureID::HitEffect, "assets/img/Efecto Golpe.png", textColor);
	createTexture(TextureID::MagicArrowEffect, "assets/img/Efecto Flecha Magica Sprite.png",textColor);
	createTexture(TextureID::MissileEffect, "assets/img/Efecto Misil Sprite.png",textColor);
	createTexture(TextureID::ExplotionEffect, "assets/img/Efecto Explosion Sprite.png",textColor);
	createTexture(TextureID::HealthEffect, "assets/img/Efecto Curar Sprite.png",textColor);
	createTexture(TextureID::Button, "assets/img/Boton.bmp");
}

TextureManager::~TextureManager() = default;
