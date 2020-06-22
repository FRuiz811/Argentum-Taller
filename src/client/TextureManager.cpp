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

TextureManager::~TextureManager() = default;
