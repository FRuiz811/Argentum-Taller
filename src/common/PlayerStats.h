#ifndef ARGENTUM_TALLER_PLAYERSTATS_H
#define ARGENTUM_TALLER_PLAYERSTATS_H


#include <zconf.h>
#include "Identificators.h"
#include "Position.h"

class PlayerStats {
private:
    Direction direction;
    uint life;
    uint mana;
    uint goldAmount;
    Position position;

public:
    PlayerStats(Direction direction, const uint &life, const uint &mana, const uint &goldAmount,
                const Position &position);

    virtual ~PlayerStats();

    Direction getDirection() const;

    uint getLife() const;

    uint getMana() const;

    uint getGoldAmount() const;

    const Position &getPosition() const;

    void setDirection(Direction direction);

    void setLife(uint life);

    void setMana(uint mana);

    void setGoldAmount(uint goldAmount);

    void setPosition(const Position &position);
};


#endif //ARGENTUM_TALLER_PLAYERSTATS_H
