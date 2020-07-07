#ifndef ARGENTUM_TALLER_CREATURE_H
#define ARGENTUM_TALLER_CREATURE_H

#include "GameObject.h"
#include "states/State.h"

class Creature : public GameObject {
private:
    uint life{};
    CreatureID creatureId;
    std::unique_ptr<State> state;

    InputInfo generateRandomInputInfo();
public:
    Creature(uint id, CreatureID creatureId, uint nestId, Point aPoint);

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                GameStatsConfig &gameStatsConfig) override;

    void notify(uint pursuitId);

    CreatureID getCreatureId() const;

    CharacterStateID getStateId() override;

    uint receiveDamage(float damage, GameStatsConfig &gameStatsConfig) override;

    virtual ~Creature();


};


#endif //ARGENTUM_TALLER_CREATURE_H
