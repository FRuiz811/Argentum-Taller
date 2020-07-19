#include "StatePoolCreature.h"
#include "StillStateCreature.h"

StatePoolCreature::StatePoolCreature() : StatePool(std::shared_ptr<State>(new StillStateCreature())) {}

void StatePoolCreature::updateState() {

}

StatePoolCreature::~StatePoolCreature() = default;
