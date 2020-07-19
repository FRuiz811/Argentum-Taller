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
	std::string path(ROOT_DIR);
	createTexture(TextureID::PresentationImage, path + "/assets/img/ImagenPresentacion.jpg");
	createTexture(TextureID::LobbyBackground, path + "/assets/img/Fondo Inicio.jpg");
	createTexture(TextureID::ZombieHead, path + "/assets/img/Zombie Cabeza.png",textColor);
	createTexture(TextureID::ElfHead,path + "/assets/img/Cabeza Elfo.png", textColor);
	createTexture(TextureID::HumanHead, path + "/assets/img/Cabeza Humano.png",textColor);
	createTexture(TextureID::DwarfHead, path + "/assets/img/Cabeza Enano.png",textColor);
	createTexture(TextureID::GnomeHead, path + "/assets/img/Cabeza Gnomo.png",textColor);
	createTexture(TextureID::PriestHead,path + "/assets/img/Sacerdote Cabeza Sprite.png", textColor);
	createTexture(TextureID::ZombieBody, path + "/assets/img/Zombie Cuerpo Sprite.png",textColor);
	createTexture(TextureID::BlueTunic,path + "/assets/img/Tunica Azul Sprite.png", textColor);
	createTexture(TextureID::PriestBody, path + "/assets/img/Sacerdote Sprite.png",textColor);
	createTexture(TextureID::LeatherArmor, path + "/assets/img/Armadura de Cuero Sprite.png",textColor);
	createTexture(TextureID::PlateArmor, path + "/assets/img/Armadura de Placas Sprite.png",textColor);
	createTexture(TextureID::BlueCommonBody, path + "/assets/img/Vestimenta Comun azul Sprite.png",textColor);
	createTexture(TextureID::GreenCommonBody, path + "/assets/img/Vestimenta Comun verde Sprite.png",textColor);
	createTexture(TextureID::RedCommonBody, path + "/assets/img/Vestimenta Comun roja Sprite.png",textColor);
	createTexture(TextureID::TurtleShield, path + "/assets/img/Escudo de Tortuga Sprite.png",textColor);
	createTexture(TextureID::IronShield, path + "/assets/img/Escudo de Hierro Sprite.png",textColor);
	createTexture(TextureID::IronHelmet, path + "/assets/img/Casco de Hierro Sprite.png", textColor);
	createTexture(TextureID::Hood, path + "/assets/img/Capucha Sprite.png",textColor);
	createTexture(TextureID::MagicHat, path + "/assets/img/Sombrero Magico Sprite.png", textColor);
	createTexture(TextureID::AshStick, path + "/assets/img/Vara de Fresno Sprite.png", textColor);
	createTexture(TextureID::LongSword, path + "/assets/img/Espada Larga Sprite.png", textColor);
	createTexture(TextureID::Hammer, path + "/assets/img/Martillo Sprite.png", textColor);
	createTexture(TextureID::SimpleArc, path + "/assets/img/Arco Simple Sprite.png", textColor);
	createTexture(TextureID::CompoundArc, path + "/assets/img/Arco Compuesto Sprite.png", textColor);
	createTexture(TextureID::GnarledStick, path + "/assets/img/Baston Nudoso Sprite.png", textColor);
	createTexture(TextureID::Crosier, path + "/assets/img/Baculo Engarzado Sprite.png", textColor);
	createTexture(TextureID::Ax, path + "/assets/img/Hacha Sprite.png", textColor);
	createTexture(TextureID::ElficFlaute, path + "/assets/img/Flauta Elfica Sprite.png", textColor);
	createTexture(TextureID::Spider, path + "/assets/img/Araña Sprite.png",textColor);
	createTexture(TextureID::Skeleton, path + "/assets/img/Esqueleto Sprite.png", textColor);
	createTexture(TextureID::Banker, path + "/assets/img/Banquero Sprite.png", textColor);
	createTexture(TextureID::Merchant, path + "/assets/img/Comerciante Sprite.png", textColor);
	createTexture(TextureID::Goblin, path + "/assets/img/Goblin.png", textColor);
	createTexture(TextureID::Ghost, path + "/assets/img/Fantasma Sprite.png", textColor);
	createTexture(TextureID::ManaPotion, path + "/assets/img/Pocion Mana.png", textColor);
	createTexture(TextureID::HealthPotion, path + "/assets/img/Pocion Vida.png", textColor);
	createTexture(TextureID::Gold, path + "/assets/img/Oro.png", textColor);
	createTexture(TextureID::ItemHood, path + "/assets/img/Capucha.png", textColor);
	createTexture(TextureID::ItemIronHelmet, path + "/assets/img/Casco de Hierro.png", textColor);
	createTexture(TextureID::ItemMagicHat, path + "/assets/img/Sombrero Magico.png", textColor);
	createTexture(TextureID::ItemIronShield, path + "/assets/img/Escudo de Hierro.png", textColor);
	createTexture(TextureID::ItemTurtleShield, path + "/assets/img/Escudo de Tortuga.png", textColor);
	createTexture(TextureID::ItemAx, path + "/assets/img/Hacha.png", textColor);
	createTexture(TextureID::ItemSimpleArc, path + "/assets/img/Arco Simple.png", textColor);
	createTexture(TextureID::ItemCompoundArc, path + "/assets/img/Arco Compuesto.png", textColor);
	createTexture(TextureID::ItemHammer, path + "/assets/img/Martillo.png", textColor);
	createTexture(TextureID::ItemLongSword, path + "/assets/img/Espada Larga.png", textColor);
	createTexture(TextureID::ItemAshStick, path + "/assets/img/Vara de Fresno.png", textColor);
	createTexture(TextureID::ItemCrosier, path + "/assets/img/Baculo Engarzado.png", textColor);
	createTexture(TextureID::ItemGnarledStick, path + "/assets/img/Baston Nudoso.png", textColor);
	createTexture(TextureID::ItemElficFlaute, path + "/assets/img/Flauta Elfica.png", textColor);
	createTexture(TextureID::ItemGreenCommonBody, path + "/assets/img/Vestimenta Comun verde.png", textColor);
	createTexture(TextureID::ItemBlueCommonBody, path + "/assets/img/Vestimenta Comun azul.png", textColor);
	createTexture(TextureID::ItemRedCommonBody, path + "/assets/img/Vestimenta Comun roja.png", textColor);
	createTexture(TextureID::ItemBlueTunic, path + "/assets/img/Tunica Azul.png", textColor);
	createTexture(TextureID::ItemLeatherArmor, path + "/assets/img/Armadura de Cuero.png", textColor);
	createTexture(TextureID::ItemPlateArmor, path + "/assets/img/Armadura de Placas.png", textColor);
	createTexture(TextureID::TopBar, path + "/assets/img/Fondo Barra Superior.jpg");
	createTexture(TextureID::Star, path + "/assets/img/Estrella.jpg", textColor);
	createTexture(TextureID::StatsBackground, path + "/assets/img/StatsBackground.jpg");
	createTexture(TextureID::ItemNothing, path + "/assets/img/RecuadroItems.jpg");
	createTexture(TextureID::MeditateEffect, path + "/assets/img/Efecto Meditar.png", textColor);
	createTexture(TextureID::HitEffect, path + "/assets/img/Efecto Golpe.png", textColor);
	createTexture(TextureID::MagicArrowEffect, path + "/assets/img/Efecto Flecha Magica Sprite.png",textColor);
	createTexture(TextureID::MissileEffect, path + "/assets/img/Efecto Misil Sprite.png",textColor);
	createTexture(TextureID::ExplotionEffect, path + "/assets/img/Efecto Explosion Sprite.png",textColor);
	createTexture(TextureID::HealthEffect, path + "/assets/img/Efecto Curar Sprite.png",textColor);
	createTexture(TextureID::Button, path + "/assets/img/Boton.bmp");
}

TextureManager::~TextureManager() = default;
