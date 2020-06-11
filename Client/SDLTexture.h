#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H
#include <string>

class SDLWindow;
class SDL_Renderer;
class SDL_Texture;
class SDL_Rect;

class SDLTexture {
private:
	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* loadTexture(const std::string &fileName);
public:
	SDLTexture(const std::string &fileName, const SDLWindow& window);

	~SDLTexture();

	int render(const SDL_Rect& source, const SDL_Rect& destiny) const;

	int render();
};

#endif
