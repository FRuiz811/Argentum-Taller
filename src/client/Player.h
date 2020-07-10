#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Camera.h"
#include "TextureManager.h"
#include "../common/Point.h"
#include "Items/Head.h"
#include "Items/Body.h"
#include "Items/Helmet.h"
#include "Items/Shield.h"
#include "Items/Weapon.h"
#include "characterStates/CharacterState.h"
#include "../common/Identificators.h"
#include "../common/PlayerInfo.h"
#include <memory>
#include <string>

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
	uint health,gold,mana;

	void setArmor(BodyID newArmor);
	void setShield(ShieldID newShield);
	void setHelmet(HelmetID newHelmet);
	void setHead(HeadID head);
	void setWeapon(WeaponID newWeapon);
	void setFrameHead();
	void setState(CharacterStateID newState);

public:
	Player(const TextureManager& manager, const PlayerInfo& playerInfo);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void updatePlayerInfo(PlayerInfo info);

	InputInfo handleEvent(SDL_Event& event, Camera& camera);
	InputInfo dropItem(int itemNumber);
	InputInfo selectItem(int itemNumber);
	InputInfo resurrect();
	InputInfo cure();
	InputInfo buy(int itemNumber);
	InputInfo sell(int itemNumber);
	Point* getCenter();

	uint getLevel();
	uint getHealth();
	uint getMana();
	uint getGold();
	uint getMaxMana();
	uint getMaxHealth();
	uint getSafeGold();
	uint getExp();
	uint getMaxExp();
	std::string getInventory();
	CharacterStateID& getState();
	PlayerInfo getInfo();

	~Player();
};

#endif
