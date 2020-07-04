#ifndef ARGENTUM_TALLER_CREATURE_H
#define ARGENTUM_TALLER_CREATURE_H

#include "GameObject.h"
#include "State.h"

class Creature : public GameObject {
private:
    uint life{};
    CreatureID creatureId;
    std::unique_ptr<State> state;
public:
    Creature();

    Creature(uint id, CreatureID creatureId, Point aPoint);

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                GameStatsConfig &gameStatsConfig) override;

    virtual ~Creature();

};


#endif //ARGENTUM_TALLER_CREATURE_H
