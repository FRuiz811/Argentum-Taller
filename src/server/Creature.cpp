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

Creature::Creature(uint id, CreatureID creatureId, uint nestId, Point aPoint) :
GameObject(id), creatureId(creatureId) {
    Position aPosition;
    switch (creatureId) {
        case CreatureID::Goblin:
            aPosition = Position(aPoint, 24, 30);
            this->textureHashId = "ht00|h00|b11|s00|w00";
            break;
        case CreatureID::Skeleton:
            aPosition = Position(aPoint, 25, 52);
            this->textureHashId = "ht00|h00|b12|s00|w00";
            break;
        case CreatureID::Spider:
            aPosition = Position(aPoint, 53, 35);
            this->textureHashId = "ht00|h00|b13|s00|w00";
            break;
        case CreatureID::Zombie:
            aPosition = Position(aPoint, 25, 61);
            this->textureHashId = "ht00|h06|b14|s00|w00";
            break;
    }
    boardPosition = BoardPosition(aPosition, nestId, false);
    this->state = std::unique_ptr<State>(new StillStateCreature());
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
    float defense = gameStatsConfig.getDefense(creatureId);
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

Creature::~Creature() = default;
