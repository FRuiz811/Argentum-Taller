#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H

class SDLWindow;
class SDL_Renderer;
class SDL_Texture;

class SDLTexture {
private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Texture* loadTexture(const std::string &fileName);
	int height;
	int width;
public:
	SDLTexture(const std::string &fileName, const SDLWindow& window);

	~SDLTexture();

	int render();
};

#endif
