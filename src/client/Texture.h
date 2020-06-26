#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include <SDL2/SDL.h>

class Texture {
private:
	SDL_Texture* texture = nullptr;
	int width;
	int height;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* loadTexture(const std::string &fileName, SDL_Color colorKey);

public:
	Texture(const std::string &fileName, SDL_Renderer& renderer, SDL_Color colorKey);
	Texture(const std::string &fileName, SDL_Renderer& renderer);
	Texture(Texture&& other);
	~Texture();

	int render(const SDL_Rect& source, const SDL_Rect& destiny) const;

	int render() const;

    int getWidth() const;

	SDL_Texture* getTexture() const;
};

#endif
