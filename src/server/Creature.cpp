#include <iostream>
#include <utility>
#include "Creature.h"
#include "states/StillStateCreature.h"
#include "states/PursuitStateCreature.h"
#include "../common/Random.h"

void Creature::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {
    statePool.updateState(generateRandomInputInfo());
    statePool.getActualState()->performTask(id, gameObjects, board);
}

Creature::Creature(uint id, CreatureID creatureId, std::shared_ptr<Cell> initialCell, Point initialPoint) :
        GameObject(id, initialPoint, std::move(initialCell)), creatureId(creatureId), statePool() {

    switch (creatureId) {
        case CreatureID::Goblin:
            this->textureHashId = "ht00|h00|b11|s00|w00";
            break;
        case CreatureID::Skeleton:
            this->textureHashId = "ht00|h00|b12|s00|w00";
            break;
        case CreatureID::Spider:
            this->textureHashId = "ht00|h00|b13|s00|w00";
            break;
        case CreatureID::Zombie:
            this->textureHashId = "ht00|h06|b14|s00|w00";
            break;
        default:
            this->textureHashId = nullptr;
            break;
    }
    life = GameStatsConfig::getMaxHealth(creatureId, level);
}

void Creature::notify(uint pursuitId) {
    if (statePool.startChasing(pursuitId)) {
        InputInfo aInputInfo;
        aInputInfo.aditional = pursuitId;
        statePool.setNextState(StateID::Pursuit, aInputInfo);
    }
}

InputInfo Creature::generateRandomInputInfo() {
    uint8_t randomId = Random::get(2,5);
    InputInfo inputInfo;
    inputInfo.input = InputID(randomId);
    return inputInfo;
}

CharacterStateID Creature::getStateId() {
    return state->getStateId();
}

CreatureID Creature::getCreatureId() const {
    return creatureId;
}

void Creature::receiveDamage(float damage, WeaponID weaponId) {
    setInteractWeapon(weaponId);
    if (GameStatsConfig::canEvade(creatureId)) {
        std::cout << "Enemy fail attack" << std::endl;
    } else {
        float defense = GameStatsConfig::getDefense(creatureId);
        float realDamage = damage - defense;
        if (realDamage > 0) {
            life = (life - realDamage > 0) ? life - realDamage : 0;
        }
        std::cout << "Character attack damage: " << damage << std::endl;
        std::cout << "Enemy defense: " << defense << std::endl;
        std::cout << "Character real damage: " << realDamage << std::endl;
        std::cout << "Enemy life is: " << life << std::endl;
        if (isDead()) {
            itemDrop = true;
            std::cout << "Enemy is dead" << realDamage << std::endl;
        }
    }
}

bool Creature::isDead() {
    return life == 0;
}

NPCInfo Creature::interact(GameObject& character, InputInfo input) {
    NPCInfo info;
    return info;
}

bool Creature::isReadyToRemove() {
    if (isDead()) {
        timeToRemove--;
    }
    return timeToRemove == 0;
}

void Creature::remove(Board &board) {
    board.removeCreatureFromNest(cell);
    cell->free();
}

float Creature::getMaxLife() {
    return GameStatsConfig::getMaxHealth(creatureId, level);
}

std::vector<DropItem> Creature::getDrop() {
    std::vector<DropItem> dropItems;
    int randomDrop = Random::get(0,100);
    ItemsInventoryID aItemInventoryId = ItemsInventoryID::Nothing;
    float amount = 0;
    if ((randomDrop > 80) && randomDrop <= 96) {
        aItemInventoryId = ItemsInventoryID::Gold;
        amount = GameStatsConfig::getGoldDrop(creatureId, level);
    } else if (randomDrop > 96 && randomDrop <= 98) {
        aItemInventoryId = ItemsInventoryID(Random::get(21, 22));
        amount = 1;
    } else if (randomDrop > 98 && randomDrop <= 100) {
        aItemInventoryId = ItemsInventoryID(Random::get(1, 20));
    }
    dropItems.emplace_back(aItemInventoryId, amount);
    itemDrop = false;
    return dropItems;
}

bool Creature::isItem() {
    return false;
}

bool Creature::canDropsItems() {
    return itemDrop;
}

bool Creature::canBeAttacked(int enemyLevel) const {
    return true;
}


Creature::~Creature() = default;
