#ifndef FONT_H
#define FONT_H
#include <SDL2/SDL_ttf.h>
#include <string>

class SDL_Texture;
class SDL_Color;
class SDL_Renderer;

class Font {
private:
	TTF_Font* font;
	int size;
	SDL_Color color;
public:
	Font(const std::string& path, const int size, SDL_Color color);

	void setColor(SDL_Color color);

	SDL_Texture* createText(const std::string& text,SDL_Renderer* renderer, int* widht, int* height);

	TTF_Font* getFont() const;

	void  deleteText(SDL_Texture* text);

	~Font();
};

#endif
