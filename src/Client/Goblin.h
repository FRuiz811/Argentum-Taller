#ifndef GOBLIN_H
#define GOBLIN_H

#include "Character.h"
#include "TextureManager.h"
#include "Items/GoblinBody.h"

union SDL_Event;


class Goblin: public Character {
private:
	GoblinBody body;

public:
	Goblin(const TextureManager& manager, int posX, int posY);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void handleEvent(SDL_Event& event);

	~Goblin();
};

#endif