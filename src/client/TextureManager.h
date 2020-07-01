#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "Texture.h"
#include "TextureID.h"
#include <unordered_map>
#include <string>
#include "../common/Identificators.h"

class SDL_Renderer;
class SDL_Color;

class TextureManager {
private:
	std::unordered_map<TextureID, Texture, std::hash<TextureID>> textures;
	SDL_Renderer& renderer;

public:
	explicit TextureManager(SDL_Renderer& renderer);

	void loadTextures();

	void createTexture(TextureID id, const std::string& path, SDL_Color color);
	void createTexture(TextureID id, const std::string& path) ;

	void dropTexture(TextureID id);

	const Texture& getTexture(TextureID id) const;

	const Texture& getTexture(ItemsInventoryID id) const;
	const Texture& getTexture(BodyID id) const;
	const Texture& getTexture(HeadID id) const;
	const Texture& getTexture(WeaponID id) const;
	const Texture& getTexture(ShieldID id) const;
	const Texture& getTexture(HelmetID id) const;
	~TextureManager();

	TextureManager(const TextureManager&) = delete;
    TextureManager &operator=(const TextureManager&) = delete;
};

#endif
