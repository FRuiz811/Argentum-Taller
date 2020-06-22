#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Character.h"
#include "TextureManager.h"
#include "Items/ZombieHead.h"
#include "Items/ZombieBody.h"

union SDL_Event;


class Zombie : public Character {
private:
	ZombieBody body;
	ZombieHead head;
	int frameHead;

public:
	Zombie(const TextureManager& manager,int posX, int posY);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void handleEvent(SDL_Event& event);

	~Zombie();
};

#endif
