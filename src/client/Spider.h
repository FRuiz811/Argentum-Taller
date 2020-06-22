#ifndef SPIDER_H
#define SPIDER_H

#include "Character.h"
#include "TextureManager.h"
#include "Items/SpiderBody.h"

union SDL_Event;


class Spider: public Character {
private:
	SpiderBody body;

public:
	Spider(const TextureManager& manager, int posX, int posY);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void handleEvent(SDL_Event& event);

	~Spider();
};

#endif
