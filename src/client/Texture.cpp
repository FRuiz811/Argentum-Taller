#include "Texture.h"
#include "Window.h"
#include <SDL2/SDL_image.h>
#include "Exception.h"
#include <iostream>

Texture::Texture(const std::string &fileName, SDL_Renderer& renderer, SDL_Color colorKey) {
	this->renderer = &renderer;
	this->texture = loadTexture(fileName, colorKey);
}

Texture::Texture(const std::string &fileName, SDL_Renderer& renderer) {
	this->renderer = &renderer;
	if (!this->texture) {
		this->texture = IMG_LoadTexture(this->renderer, fileName.c_str());
	}
	if (!this->texture){
		throw Exception("Fail IMG_LoadTexture: %s ", IMG_GetError());
	}
	int h,w;
	SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
	this->width = w;
	this->height = h;
}


Texture::Texture(Texture &&other) {
    std::swap(this->texture, other.texture);
    std::swap(this->renderer, other.renderer);
    std::swap(this->height, other.height);
    std::swap(this->width, other.width);
}

SDL_Texture* Texture::loadTexture(const std::string &fileName, SDL_Color colorKey) {
	SDL_Surface* surface = IMG_Load(fileName.c_str());
	if (!surface) {
		throw Exception("Fail IMG_Load: %s", IMG_GetError());
	}
	SDL_SetColorKey( surface, SDL_TRUE,
		SDL_MapRGB(surface->format, colorKey.r, colorKey.g, colorKey.b));
	this->width = surface->w;
	this->height = surface->h;
	this->texture = SDL_CreateTextureFromSurface(this->renderer,surface);

	if (!this->texture){
		throw Exception("Fail SDL_CreateTextureFromSurface: %s", SDL_GetError());
	}
	SDL_FreeSurface(surface);
	return this->texture;
}

int Texture::render() const {
	return SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
}

int Texture::render(const SDL_Rect& source, const SDL_Rect& destiny) const {
	return SDL_RenderCopy(this->renderer, this->texture, &source, &destiny);
}

Texture::~Texture() {
	if (this->texture) {
		SDL_DestroyTexture(this->texture);
		this->texture = nullptr;
	}
}

int Texture::getWidth() const {
    return width;
}

SDL_Texture* Texture::getTexture() const {
	return this->texture;
}
