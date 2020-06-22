#ifndef PRIEST_H
#define PRIEST_H

#include "Character.h"
#include "Items/PriestHead.h"
#include "Items/PriestBody.h"
union SDL_Event;


class Priest: public Character{
private:
	PriestBody body;
	PriestHead head;
	int frameHead;

public:
	Priest(const TextureManager& manager, int posX, int posY);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void handleEvent(SDL_Event& event);

	~Priest();
};

#endif
