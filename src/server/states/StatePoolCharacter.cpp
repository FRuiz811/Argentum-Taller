#include "StatePoolCharacter.h"
#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"
#include "EquipStateCharacter.h"
#include "InteractStateCharacter.h"
#include "AttackStateCharacter.h"
#include "MeditateStateCharacter.h"
#include "TakeAndDropStateCharacter.h"
#include "ResurrectStateCharacter.h"

StatePoolCharacter::StatePoolCharacter(GameObject &aGameObject) : StatePool(std::shared_ptr<State>(new StillStateCharacter())), character(aGameObject) {}

void StatePoolCharacter::updateState(InputInfo aInputInfo) {
    if (actualState->isOver()) {
        StateID nextStateId;
        if (aInputInfo.input != InputID::nothing) {
            nextStateId = actualState->getNextStateID(aInputInfo);
        } else {
            nextStateId = actualState->getResetStateID();
        }
        setNextState(nextStateId, aInputInfo);
    }
}

void StatePoolCharacter::setNextState(StateID id, InputInfo aInputInfo) {
    if (id == StateID::Transition) {
        id = character.getActualCell()->isCity() ? StateID::Interact : StateID::Attack;
    }
    if (character.isDead() && !isPossibleDeadState(id)) {
        return;
    }
    changeState(id, aInputInfo);
}

bool StatePoolCharacter::isPossibleDeadState(StateID id) {
    return id == StateID::Still || id == StateID::Move || id == StateID::Interact || id == StateID::Resurrect;
}

void StatePoolCharacter::changeState(StateID id, InputInfo aInputInfo) {
    std::shared_ptr<State> nextState;
    try {
        nextState = states.at(id);
    } catch (std::exception &e) {
        nextState = generateState(id);
    }
    actualState = nextState;
}

std::shared_ptr<State> StatePoolCharacter::generateState(StateID id) {
    std::shared_ptr<State> newState;
    switch (id) {
        case StateID::Move:
            newState = std::shared_ptr<State>(new MoveStateCharacter());
            break;
        case StateID::Equip:
            newState = std::shared_ptr<State>(new EquipStateCharacter());
            break;
        case StateID::Interact:
            newState = std::shared_ptr<State>(new InteractStateCharacter());
            break;
        case StateID::Attack:
            newState = std::shared_ptr<State>(new AttackStateCharacter());
            break;
        case StateID::Meditate:
            newState = std::shared_ptr<State>(new MeditateStateCharacter());
            break;
        case StateID::TakeDrop:
            newState = std::shared_ptr<State>(new TakeAndDropStateCharacter());
            break;
        case StateID::Resurrect:
            newState = std::shared_ptr<State>(new ResurrectStateCharacter());
            break;
        default:
            break;
    }
    return newState;
}

StatePoolCharacter::~StatePoolCharacter() = default;
