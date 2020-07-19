#include "StatePool.h"

#include <utility>

StatePool::~StatePool() = default;

StatePool::StatePool(std::shared_ptr<State> firstState) : actualState(std::move(firstState)) {

}
