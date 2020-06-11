#include "SDLTexture.h"
#include "SDLWindow.h"
#include <SDL2/SDL_image.h>
#include "SDLException.h"

SDLTexture::SDLTexture(const std::string &fileName, const SDLWindow& window) :
	renderer(window.getRenderer()) {
	this->texture = loadTexture(fileName);

}

SDL_Texture* SDLTexture::loadTexture(const std::string &fileName) {
	if (!this->texture) {
		this->texture = IMG_LoadTexture(this->renderer, fileName.c_str());
	}
	if (!this->texture){
		throw SDLException("Fail IMG_LoadTexture: %s", IMG_GetError());
	}
	return this->texture;
}

int SDLTexture::render() {
	return SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
}

int SDLTexture::render(const SDL_Rect& source, const SDL_Rect& destiny) const {
	return SDL_RenderCopy(this->renderer, this->texture, &source, &destiny);
}

SDLTexture::~SDLTexture() {
	if (this->texture)
		SDL_DestroyTexture(this->texture);
}
