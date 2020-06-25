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
	createTexture(TextureID::GnarledStick, "assets/img/Baston Nudoso.png", textColor);
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
}

TextureManager::~TextureManager() = default;
