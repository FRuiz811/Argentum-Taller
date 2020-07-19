#include "State.h"

State::State() = default;

State::State(InputInfo anInputInfo): inputInfo(std::move(anInputInfo)) {}

State::~State() = default;

bool State::isOver() const {
    return finalized;
}

StateID State::getStateId() const {
    return stateId;
}




