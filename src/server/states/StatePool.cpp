#include "StatePool.h"

#include <utility>

StatePool::~StatePool() = default;

StatePool::StatePool(std::shared_ptr<State> firstState) : actualState(std::move(firstState)) {
    states.insert(std::pair<StateID, std::shared_ptr<State>>(actualState->getStateId(), actualState));
}

const std::shared_ptr<State> &StatePool::getActualState() const {
    return actualState;
}

StateID StatePool::getStateId() {
    return actualState->getStateId();
}
