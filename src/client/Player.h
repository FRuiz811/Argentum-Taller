#ifndef PLAYER_H
#define PLAYER_H

#include "Texture.h"
#include "TextureManager.h"
#include "Point.h"
#include "Items/Head.h"
#include "Items/Body.h"
#include "Camera.h"

union SDL_Event;


class Player {
private:
	Head* head;
	Body* body;
	Point center;
	const TextureManager& manager;
	int frameBody, widthBody, heightBody, rowBody;
	int frameHead, widthHead, heightHead, rowHead;
	int animSpeed, totalFrames;
	int posX, posY;

public:
	Player(const TextureManager& manager,int posX, int posY);

	void render(Camera& camera);
	void update(double dt);

	/*void setArmor(Armor newArmor);

	void setShield(Shield newShield);

	void setHelmet(Helmet newHelmet);

	void setWeapon(Weapon newWeapon);*/

	Point* getCenter();
	void handleEvent(SDL_Event& event);

	~Player();
};

#endif
