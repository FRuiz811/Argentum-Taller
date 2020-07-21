#include "State.h"

State::State() {
    InputInfo info;
    info.input = InputID::nothing;
    inputInfo = info;
    stateId = StateID::Still;
}

State::~State() = default;

bool State::isOver() const {
    return finalized;
}

StateID State::getStateId() const {
    return stateId;
}

const InputInfo &State::getInputInfo() const {
    return inputInfo;
}




