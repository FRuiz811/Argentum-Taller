#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Camera.h"
#include "TextureManager.h"
#include "MusicManager.h"
#include "../common/Point.h"
#include "characterStates/CharacterState.h"
#include "../common/Identificators.h"
#include "../common/PlayerInfo.h"
#include <memory>
#include <string>

union SDL_Event;


class Player : public Character {
private:
	Point center;
	PlayerInfo playerInfo;
	std::shared_ptr<CharacterState> state = nullptr;
	bool playLowLife{false};

	void setState(CharacterStateID newState);
	void playEffectLowLife();

public:
	Player(const TextureManager& manager, const PlayerInfo& playerInfo, const MusicManager& mixer);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void updatePlayerInfo(const PlayerInfo& info);

	InputInfo handleEvent(SDL_Event& event, Camera& camera);
	InputInfo dropItem(int itemNumber);
	InputInfo selectItem(int itemNumber);
	InputInfo resurrect();
	InputInfo cure();
	InputInfo buy(int itemNumber);
	InputInfo sell(int itemNumber);
	InputInfo deposit(int information, bool isItem);
	InputInfo retire(int information, bool isItem);
	InputInfo unequipItem(int itemNumber);
	Point* getCenter();

	uint getLevel() const;
	uint getHealth() const;
	uint getMana() const;
	uint getGold() const;
	uint getMaxMana() const;
	uint getMaxHealth() const;
	uint getSafeGold() const;
	uint getExp() const;
	uint getMaxExp() const;
	std::string getInventory() const;
	CharacterStateID& getState() const;
	PlayerInfo getInfo() const;

	~Player();
};

#endif
