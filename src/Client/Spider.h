#ifndef SPIDER_H
#define SPIDER_H

#include "Texture.h"
#include "TextureManager.h"

union SDL_Event;


class Spider {
private:
	const TextureManager& manager;
	int frame, width, height, row;
	int animSpeed, totalFrames;
	int posX, posY;

public:
	Spider(const TextureManager& manager);

	void render(const int width_screen, const int height_screen);
	void update(double dt);

	void handleEvent(SDL_Event& event);

	~Spider();
};

#endif
