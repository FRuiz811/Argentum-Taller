#include "StateCreature.h"

StateCreature::~StateCreature() = default;

StateID StateCreature::getResetStateID() {
    return StateID::Still;
}
