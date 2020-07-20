#include "Font.h"
#include "../common/Exception.h"
#include "../common/Identificators.h"

Font::Font(const std::string& path, const int size, SDL_Color color) : size(size),
	color(color) {
	std::string root(ROOT_DIR+std::string("/")+path);
	this->font = TTF_OpenFont(root.c_str(), this->size);
	if (!this->font)
		throw Exception("Fail TTF_OpenFont: %s", TTF_GetError());
}


void Font::setColor(SDL_Color color) {
	this->color = color;
}

void Font::setSize(int size) {
	this->size = size;
}

SDL_Texture* Font::createText(const std::string& text, SDL_Renderer* renderer, int* width, int* height) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(this->font, text.c_str(), this->color);
	if (!textSurface)
		throw Exception("Fail TTF_RenderText_Solid: %s", TTF_GetError());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (!texture)
		throw Exception("Fail SDL_CreateTextureFromSurface in createText: %s", SDL_GetError());
	
	*height = textSurface->h;	
	*width = textSurface->w;
	SDL_FreeSurface(textSurface);
	return texture;
}

TTF_Font* Font::getFont() const {
	return this->font;
}

void Font::deleteText(SDL_Texture* text) {
	SDL_DestroyTexture(text);
}

Font::~Font(){
	if(this->font) {
		TTF_CloseFont(this->font);
		this->font = nullptr;
	}
}