#include "StatePoolCharacter.h"
#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"
#include "EquipStateCharacter.h"
#include "InteractStateCharacter.h"
#include "AttackStateCharacter.h"
#include "MeditateStateCharacter.h"
#include "TakeAndDropStateCharacter.h"
#include "ResurrectStateCharacter.h"

StatePoolCharacter::StatePoolCharacter(GameObject &aGameObject) : character(aGameObject),
actualState(std::shared_ptr<StateCharacter>(new StillStateCharacter())) {
    states.insert(std::pair<StateID,
            std::shared_ptr<StateCharacter>>(actualState->getStateId(), actualState));
}

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
    std::shared_ptr<StateCharacter> nextState;
    try {
        nextState = states.at(id);
    } catch (std::exception &e) {
        nextState = generateState(id);
    }
    nextState->init(aInputInfo);
    actualState = nextState;
}

std::shared_ptr<StateCharacter> StatePoolCharacter::generateState(StateID stateId) {
    std::shared_ptr<StateCharacter> newState;
    switch (stateId) {
        case StateID::Move:
            newState = std::shared_ptr<StateCharacter>(new MoveStateCharacter());
            break;
        case StateID::Equip:
            newState = std::shared_ptr<StateCharacter>(new EquipStateCharacter());
            break;
        case StateID::Interact:
            newState = std::shared_ptr<StateCharacter>(new InteractStateCharacter());
            break;
        case StateID::Attack:
            newState = std::shared_ptr<StateCharacter>(new AttackStateCharacter());
            break;
        case StateID::Meditate:
            newState = std::shared_ptr<StateCharacter>(new MeditateStateCharacter());
            break;
        case StateID::TakeDrop:
            newState = std::shared_ptr<StateCharacter>(new TakeAndDropStateCharacter());
            break;
        case StateID::Resurrect:
            newState = std::shared_ptr<StateCharacter>(new ResurrectStateCharacter());
            break;
        default:
            break;
    }
    return newState;
}

StatePoolCharacter::~StatePoolCharacter() = default;
