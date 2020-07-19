#include "StatePoolCreature.h"
#include "StillStateCreature.h"

StatePoolCreature::StatePoolCreature() : StatePool(std::shared_ptr<State>(new StillStateCreature())) {}

void StatePoolCreature::updateState(InputInfo aInputInfo) {
    if (actualState->isOver()) {
        StateID nextStateId = actualState->getNextStateID(aInputInfo);
        setNextState(nextStateId, aInputInfo);
    }
}

void StatePoolCreature::setNextState(StateID id, InputInfo info) {
    if () {
        return;
    }
    changeState(id, aInputInfo);
}

StatePoolCreature::~StatePoolCreature() = default;
