#ifndef FONT_H
#define FONT_H
#include <SDL2/SDL_ttf.h>
#include <string>

class Font {
private:
	TTF_Font* font;
	int size;

public:
	Font(const std::string path, const int size);

	TTF_Font* getFont() const;
	~Font();
};

#endif
