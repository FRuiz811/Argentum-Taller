#ifndef PLAYER_H
#define PLAYER_H

#include "Texture.h"
#include "TextureManager.h"

union SDL_Event;


class Player {
private:
	const TextureManager& manager;
	int frameBody, widthBody, heightBody, rowBody;
	int frameHead, widthHead, heightHead, rowHead;
	int animSpeed, totalFrames;
	int posX, posY;

public:
	Player(const TextureManager& manager);

	void render(const int width_screen, const int height_screen);
	void update(double dt);

	void handleEvent(SDL_Event& event);

	~Player();
};

#endif
