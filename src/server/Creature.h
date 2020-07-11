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
    Creature(uint id, CreatureID creatureId, std::shared_ptr<Cell> initialCell, Point initialPoint);

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void notify(uint pursuitId);

    CreatureID getCreatureId() const;

    bool isDead();

    float getMaxLife() override;

    CharacterStateID getStateId() override;

    uint receiveDamage(float damage) override;

    virtual NPCInfo interact(GameObject& character, InputInfo input);
    
    virtual ~Creature();

    void remove(Board &board) override;

    bool isReadyToRemove() override;

};


#endif //ARGENTUM_TALLER_CREATURE_H
