#include "SDLTexture.h"
#include "SDLWindow.h"

SDLTexture::SDLTexture(const std::string &fileName, const SDLWindow& window) :
	renderer(window.getRenderer()) {
	this->texture = loadTexture(fileName);
}

SDLTexture::~SDLTexture() {
	SDL_DestroyTexture(this->texture);
}

SDL_Texture* SDLTexture::loadTexture(const std::string &fileName) {
	if (!this->texture) 
		this->texture = IMG_LoadTexture(this->renderer, fileName.data());
}