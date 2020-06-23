#ifndef PLAYER_H
#define PLAYER_H

#include "Texture.h"
#include "Character.h"
#include "TextureManager.h"
#include "Point.h"
#include "Items/Head.h"
#include "Items/Body.h"
#include "Items/Helmet.h"
#include "Items/Shield.h"
#include "Items/Weapon.h"
#include "characterStates/CharacterState.h"
#include "characterStates/CharacterStatesID.h"
#include "Camera.h"
#include "../common/ServerProxy.h"
#include "PlayerInfo.h"
#include <memory>

union SDL_Event;


class Player : public Character {
private:
	Point center;
	const TextureManager& manager;
	PlayerInfo playerInfo;	
	std::shared_ptr<Body>  body = nullptr;
	std::shared_ptr<CharacterState> state = nullptr;
	std::shared_ptr<Head> head = nullptr;
	std::shared_ptr<Helmet> helmet = nullptr;
	std::shared_ptr<Shield> shield = nullptr;
	std::shared_ptr<Weapon> weapon = nullptr;
	int frameHead;
	bool isAlive{true};

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

	void setArmor(BodyID newArmor);
	void setShield(ShieldID newShield);
	void setHelmet(HelmetID newHelmet);
	void setHead(HeadID head);
	void setWeapon(WeaponID newWeapon);

public:
	Player(const TextureManager& manager, PlayerInfo playerInfo);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void setState(CharacterStateID newState);

	Point* getCenter();
	void handleEvent(SDL_Event& event, ServerProxy&);

	~Player();
};

#endif
