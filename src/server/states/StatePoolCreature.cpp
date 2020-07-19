#include "StatePoolCreature.h"
#include "StillStateCreature.h"
#include "AttackStateCreature.h"
#include "MoveStateCreature.h"
#include "PursuitStateCreature.h"

StatePoolCreature::StatePoolCreature() :
actualState(std::shared_ptr<StateCreature>(new StillStateCreature())) {
    states.insert(std::pair<StateID,
            std::shared_ptr<StateCreature>>(actualState->getStateId(), actualState));
}

void StatePoolCreature::updateState(InputInfo aInputInfo) {
    if (actualState->isOver()) {
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
    return newState;
}

bool StatePoolCreature::startChasing(uint pursuitId) {
    return !actualState->isAttacking() && !actualState->isOnPursuit(pursuitId);
}

StatePoolCreature::~StatePoolCreature() = default;
