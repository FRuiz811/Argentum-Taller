#include "StatePoolCreature.h"
#include "StillStateCreature.h"
#include "AttackStateCreature.h"
#include "MoveStateCreature.h"
#include "PursuitStateCreature.h"

StatePoolCreature::StatePoolCreature(GameObject &aCreature) : creature(aCreature),
actualState(std::shared_ptr<StateCreature>(new StillStateCreature())) {
    states.insert(std::pair<StateID,
            std::shared_ptr<StateCreature>>(actualState->getStateId(), actualState));
}

void StatePoolCreature::updateState() {
    if (actualState->isOver()) {
        InputInfo aInputInfo;
        if (actualState->getStateId() == StateID::Pursuit || actualState->getStateId() == StateID::Attack) {
            aInputInfo = actualState->getInputInfo();
        } else {
            aInputInfo = creature.getNextInputInfo();
        }
        StateID nextStateId = actualState->getNextStateID(aInputInfo);
        setNextState(nextStateId, aInputInfo);
    }
}

void StatePoolCreature::setNextState(StateID id, InputInfo aInputInfo) {
    changeState(id, aInputInfo);
}

void StatePoolCreature::changeState(StateID id, InputInfo aInputInfo) {
    std::shared_ptr<StateCreature> nextState;
    try {
        nextState = states.at(id);
    } catch (std::exception &e) {
        nextState = generateState(id);
    }
    nextState->init(aInputInfo);
    actualState = nextState;
}

std::shared_ptr<StateCreature> StatePoolCreature::generateState(StateID stateId) {
    std::shared_ptr<StateCreature> newState;
    switch (stateId) {
        case StateID::Move:
            newState = std::shared_ptr<StateCreature>(new MoveStateCreature());
            break;
        case StateID::Attack:
            newState = std::shared_ptr<StateCreature>(new AttackStateCreature());
            break;
        case StateID::Pursuit:
            newState = std::shared_ptr<StateCreature>(new PursuitStateCreature());
            break;
        default:
            break;
    }
    states.insert(std::pair<StateID,
            std::shared_ptr<StateCreature>>(newState->getStateId(), newState));
    return newState;
}

bool StatePoolCreature::startChasing(uint pursuitId) {
    return !actualState->isAttacking() && !actualState->isOnPursuit(pursuitId);
}

StateID StatePoolCreature::getStateId() {
    return actualState->getStateId();
}

void StatePoolCreature::performTask(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {
    actualState->performTask(creature.getId(), gameObjects, board);
}

StatePoolCreature::~StatePoolCreature() = default;
