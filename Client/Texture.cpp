#include "Texture.h"
#include "Window.h"
#include <SDL2/SDL_image.h>
#include "Exception.h"
#include <iostream>

Texture::Texture(const std::string &fileName, SDL_Renderer& renderer) {
	this->renderer = &renderer;
	this->texture = loadTexture(fileName);
}

Texture::Texture(Texture &&other) {
    std::swap(this->texture, other.texture);
    std::swap(this->renderer, other.renderer);
}

SDL_Texture* Texture::loadTexture(const std::string &fileName) {
	if (!this->texture) {
		this->texture = IMG_LoadTexture(this->renderer, fileName.c_str());
	}
	if (!this->texture){
		throw Exception("Fail IMG_LoadTexture: %s", IMG_GetError());
	}
	int h,w;
	SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
	this->width = w;
	this->height = h;
	return this->texture;
}

int Texture::render() {
	return SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
}

int Texture::render(const SDL_Rect& source, const SDL_Rect& destiny) const {
	return SDL_RenderCopy(this->renderer, this->texture, &source, &destiny);
}

Texture::~Texture() {
	if (this->texture)
		SDL_DestroyTexture(this->texture);
}
