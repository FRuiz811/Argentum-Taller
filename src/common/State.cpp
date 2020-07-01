#include "State.h"

#include <utility>

State::State(InputInfo anInputInfo): inputInfo(std::move(anInputInfo)) {}

State::~State() = default;

bool State::isOver() const {
    return finalized;
}

bool State::hasNextState() {
    return nextState != nullptr;
}

std::unique_ptr<State> State::getNextState() {
    return std::move(nextState);
}

CharacterStateID State::getStateId() const {
    return stateId;
}


