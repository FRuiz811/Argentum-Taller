#ifndef PERSONAJE_H
#define PERSONAJE_H


#include "PlayerInfo.h"
#include "StaticObject.h"
#include "State.h"
#include "InputQueue.h"
#include <vector>
#include <unordered_map>
#include <memory>
#include "GameStats.h"

class GameCharacter : public GameObject{
private:
    RaceID race{};
    GameClassID gameClass{};
    uint goldAmount;
    uint life;
    uint mana;
    float exp;
    uint level{};
    std::unique_ptr<State> state;
    InputQueue queueInputs;
public:
	GameCharacter(uint id, RaceID aRace, GameClassID aClass, Point& point);

	PlayerInfo getPlayerInfo();

	void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig& gameStatsConfig) override;

    void receiveInput(InputInfo inputInfo);

    ~GameCharacter();

    RaceID getRace() const;

    GameClassID getGameClass() const;

    uint getGoldAmount() const;

    uint getLife() const;

    uint getMana() const;

    float getExp() const;

    uint getLevel() const;

    InputQueue &getQueueInputs();
};

#endif
