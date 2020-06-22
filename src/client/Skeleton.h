#ifndef SKELETON_H
#define SKELETON_H

#include "Character.h"
#include "TextureManager.h"
#include "Items/SkeletonBody.h"

union SDL_Event;


class Skeleton: public Character {
private:
	SkeletonBody body;

public:
	Skeleton(const TextureManager& manager, int posX, int posY);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void handleEvent(SDL_Event& event);

	~Skeleton();
};

#endif
