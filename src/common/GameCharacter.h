#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "GameObject.h"
#include "../client/PlayerInfo.h"

class GameCharacter : public GameObject{
private:
    int race{};
    int gameClass{};
    uint goldAmount;
    uint life;
    uint mana;

public:
	GameCharacter(uint id, int aRace, int aClass, Point& point);

	PlayerInfo getPlayerInfo();

	void update() override;

    ~GameCharacter();
};

#endif
