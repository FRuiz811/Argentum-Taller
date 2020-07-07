#include <ctime>
#include "Creature.h"
#include "StillStateCreature.h"
#include "PursuitStateCreature.h"

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
    std::srand((int)std::time(nullptr));
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

void Creature::notify(uint id) {
    state = std::unique_ptr<State>(new PursuitStateCreature(id));
}

InputInfo Creature::generateRandomInputInfo() {
    InputInfo inputInfo;
    uint8_t randomId = 1 + std::rand() % 5;
    inputInfo.input = InputID(randomId);
    return inputInfo;
}

CharacterStateID Creature::getStateId() {
    return state->getStateId();
}

Creature::~Creature() = default;
