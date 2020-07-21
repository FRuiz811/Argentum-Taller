#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
#include "GameCharacter.h"
#include "Profession.h"
#include "states/State.h"

class NPCServer : public GameObject{
private:
    Profession* profession;
public:
	NPCServer(uint id, const std::string& type, Point initialPoint, std::shared_ptr<Cell> initialCell);

    virtual ~NPCServer();

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override ;

    CharacterStateID getStateId() override;

    NPCInfo interact(GameObject& character, InputInfo input) override;

    void receiveDamage(float damage, WeaponID weaponId) override;

    bool isItem() override;

    bool canDropsItems() override;

    PlayerInfo getPlayerInfo() override;

    bool hasAnInputInfo() override;

    InputInfo getNextInputInfo() override;

    float getMaxLife() override;

    std::vector<DropItem> getDrop() override;

    bool isDead() override;

    void remove(Board &board) override;

    bool isReadyToRemove() override;

    bool canBeAttacked(int enemyLevel) const override ;
};

#endif
