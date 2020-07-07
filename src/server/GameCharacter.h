#ifndef PERSONAJE_H
#define PERSONAJE_H


#include "../common/PlayerInfo.h"
#include "../common/StaticObject.h"
#include "states/State.h"
#include "../common/InputQueue.h"
#include <vector>
#include <unordered_map>
#include <memory>
#include "GameStats.h"

class GameCharacter : public GameObject{
private:
    RaceID race{RaceID::Nothing};
    GameClassID gameClass{GameClassID::Nothing};
    uint goldAmount;
    uint life;
    uint mana;
    float exp;
    uint level{};
    std::unique_ptr<State> state;
    std::string inventory;
    InputQueue queueInputs;
    WeaponID weapon{WeaponID::Nothing};
    ShieldID shield{ShieldID::Nothing};
    HelmetID helmet{HelmetID::Nothing};
    BodyID body{BodyID::Nothing};

    std::string updateTextureHashId();
public:
	GameCharacter(uint id, RaceID aRace, GameClassID aClass, Point& point);

	PlayerInfo getPlayerInfo();

	bool hasAnInputInfo();

	InputInfo getNextInputInfo();

	void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig& gameStatsConfig) override;

    uint receiveDamage(float damage, GameStatsConfig& gameStatsConfig) override;

    bool isDead();

    ~GameCharacter();

    RaceID getRace() const;

    GameClassID getGameClass() const;

    uint getGoldAmount() const;

    CharacterStateID getStateId() override;

    uint getLife() const;

    uint getMana() const;

    float getExp() const;

    uint getLevel() const;

    InputQueue &getQueueInputs();
};

#endif
