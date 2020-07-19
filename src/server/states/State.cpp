#include "State.h"

State::State() {
    InputInfo info;
    info.input = InputID::nothing;
    inputInfo = info;
    stateId = StateID::Still;
};

State::State(InputInfo anInputInfo): inputInfo(std::move(anInputInfo)) {
    stateId = StateID::Still;
}

State::~State() = default;

bool State::isOver() const {
    return finalized;
}

StateID State::getStateId() const {
    return stateId;
}




