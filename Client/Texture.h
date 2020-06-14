#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

class Window;
class SDL_Renderer;
class SDL_Texture;
class SDL_Rect;

class Texture {
private:
	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* loadTexture(const std::string &fileName);
public:
	Texture(const std::string &fileName, SDL_Renderer& renderer);
	Texture(Texture&& other);
	~Texture();

	int render(const SDL_Rect& source, const SDL_Rect& destiny) const;

	int render();
};

#endif
