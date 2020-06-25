#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "TextureManager.h"
#include "../common/Point.h"
#include "Items/Head.h"
#include "Items/Body.h"
#include "Items/Helmet.h"
#include "Items/Shield.h"
#include "Items/Weapon.h"
#include "characterStates/CharacterState.h"
#include "../common/Identificators.h"
#include "../common/ServerProxy.h"
#include "PlayerInfo.h"
#include <memory>

union SDL_Event;


class Player : public Character {
private:
	//int id{0};
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
	int health,gold,mana;

	void setArmor(BodyID newArmor);
	void setShield(ShieldID newShield);
	void setHelmet(HelmetID newHelmet);
	void setHead(HeadID head);
	void setWeapon(WeaponID newWeapon);
	void setFrameHead();

public:
	Player(const TextureManager& manager, const PlayerInfo& playerInfo);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void setState(CharacterStateID newState);

	void updatePlayerInfo(PlayerInfo info);

	Point* getCenter();
	InputInfo handleEvent(SDL_Event& event, ServerProxy&);

	~Player();
};

#endif
