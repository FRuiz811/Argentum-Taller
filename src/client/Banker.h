#ifndef BANKER_H
#define BANKER_H

#include "Character.h"
#include "Items/BankerBody.h"
union SDL_Event;


class Banker: public Character{
private:
	BankerBody body;
	int frameHead;

public:
	Banker(const TextureManager& manager, int posX, int posY);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void handleEvent(SDL_Event& event);

	~Banker();
};

#endif
