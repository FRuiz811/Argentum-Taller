#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "Texture.h"
#include "TextureID.h"
#include <unordered_map>
#include <string>

class SDL_Renderer;

class TextureManager {
private:
	std::unordered_map<TextureID, Texture, std::hash<TextureID>> textures;
	SDL_Renderer& renderer;

public:
	TextureManager(SDL_Renderer& renderer);

	void createTexture(TextureID id, std::string path);

	void dropTexture(TextureID id);

	Texture& getTexture(TextureID id);

	~TextureManager();

	TextureManager(const TextureManager&) = delete;
    TextureManager &operator=(const TextureManager&) = delete;
};

#endif
