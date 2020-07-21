#ifndef ARGENTUM_TALLER_CREATURE_H
#define ARGENTUM_TALLER_CREATURE_H

#include <states/StatePoolCreature.h>
#include "GameObject.h"
#include "states/State.h"

class Creature : public GameObject {
private:
    uint life{};
    CreatureID creatureId;
    bool itemDrop = false;
    uint8_t timeToRemove = 10;
    StatePoolCreature statePool;

    InputInfo generateRandomInputInfo();
public:
    Creature(uint id, CreatureID creatureId, std::shared_ptr<Cell> initialCell, Point initialPoint);

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void notify(uint pursuitId);

    CreatureID getCreatureId() const;

    PlayerInfo getPlayerInfo() override;

    bool hasAnInputInfo() override;

    InputInfo getNextInputInfo() override;

    bool isDead() override;

    bool canDropsItems() override;

    bool isItem() override;

    std::vector<DropItem> getDrop() override;

    float getMaxLife() override;

    void receiveDamage(float damage, WeaponID weaponId) override;

    CharacterStateID getStateId() override;

    NPCInfo interact(GameObject& character, InputInfo input) override;
    
    virtual ~Creature();

    void remove(Board &board) override;

    bool isReadyToRemove() override;

    bool canBeAttacked(int enemyLevel) const override;

};


#endif //ARGENTUM_TALLER_CREATURE_H
