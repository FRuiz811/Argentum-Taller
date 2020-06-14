#include "Font.h"
#include "Exception.h"

Font::Font(const std::string path, const int size) : size(size) {
	this->font = TTF_OpenFont(path.c_str(), this->size);
	if (!this->font)
		throw Exception("Fail TTF_OpenFont: ", TTF_GetError());
}

TTF_Font* Font::getFont() const {
	return this->font;
}

Font::~Font(){
	if(this->font)
		TTF_CloseFont(this->font);
}