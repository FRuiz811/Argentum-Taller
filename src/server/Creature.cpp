#include <iostream>
#include "Creature.h"
#include "states/StillStateCreature.h"
#include "states/PursuitStateCreature.h"
#include "../common/Random.h"
#include "states/DeadStateCreature.h"

void Creature::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                      GameStatsConfig &gameStatsConfig) {
    if (state->isOver()) {
        state->setNextState(generateRandomInputInfo());
        if (state->hasNextState()) {
            state = state->getNextState();
        }
    }
    state->performTask(id, gameObjects, board, gameStatsConfig);
}

Creature::Creature(uint id, CreatureID creatureId, std::shared_ptr<Cell> initialCell, Point initialPoint) :
        GameObject(id, initialPoint, initialCell), creatureId(creatureId) {

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
    }
    this->state = std::unique_ptr<State>(new StillStateCreature());
    life = 50;
}

void Creature::notify(uint pursuitId) {
    if (!state->isOnPursuit(pursuitId) && !state->isAttacking()) {
        state = std::unique_ptr<State>(new PursuitStateCreature(pursuitId));
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

uint Creature::receiveDamage(float damage, GameStatsConfig &gameStatsConfig) {
    float defense = GameStatsConfig::getDefense(creatureId);
    float realDamage = damage - defense;
    if (realDamage > 0) {
        life = (life - realDamage > 0) ? life - realDamage : 0;
    }
    std::cout << "Character attack damage: " << damage << std::endl;
    std::cout << "Enemy defense: " << defense << std::endl;
    std::cout << "Character real damage: " << realDamage << std::endl;
    if (isDead()) {
        state = std::unique_ptr<State>(new DeadStateCreature());
    }
    return life;
}

bool Creature::isDead() {
    return life = 0;
}

NPCInfo Creature::interact(GameObject& character, InputInfo input) {
    NPCInfo info;
    return info;
}

bool Creature::isReadyToRemove() {
    return isDead();
}

void Creature::remove(Board &board) {
    board.removeCreatureFromNest(cell);
    cell->free();
}

Creature::~Creature() = default;
