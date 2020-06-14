#include "TextureManager.h"
#include <utility>

TextureManager::TextureManager(SDL_Renderer& renderer) : textures(),
	renderer(renderer) {}


void TextureManager::createTexture(TextureID id, std::string path) {
	Texture newTexture(path, this->renderer);
	this->textures.insert(std::make_pair(id, std::move(newTexture)));
}

void TextureManager::dropTexture(TextureID id) {
	this->textures.erase(id);
}

Texture& TextureManager::getTexture(TextureID id) {
	return this->textures.at(id);
}

TextureManager::~TextureManager() {
	this->textures.clear();
}
