#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "GameObject.h"
#include "../client/PlayerInfo.h"
#include "StaticObject.h"
#include <vector>
#include <unordered_map>
#include <memory>

class GameCharacter : public GameObject{
private:
    int race{};
    int gameClass{};
    uint goldAmount;
    uint life;
    uint mana;
    Direction direction;

public:
	GameCharacter(uint id, int aRace, int aClass, Point& point);

	PlayerInfo getPlayerInfo();

	void move(Direction aDirection,const std::unordered_map<uint, std::shared_ptr<GameObject>>&, const std::vector<StaticObject>&);

	void update() override;

    ~GameCharacter();
};

#endif
