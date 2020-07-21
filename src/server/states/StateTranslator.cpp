#include "StateTranslator.h"

StateTranslator::StateTranslator() = default;

StateTranslator::~StateTranslator() = default;

CharacterStateID StateTranslator::stateToCharacterState(StateID stateId) {
    CharacterStateID characterStateId = CharacterStateID::Still;
    switch (stateId) {
        case StateID::Still:
            characterStateId = CharacterStateID::Still;
            break;
        case StateID::Move:
            characterStateId = CharacterStateID::Move;
            break;
        case StateID::Equip:
            characterStateId = CharacterStateID::Still;
            break;
        case StateID::Transition:
            characterStateId = CharacterStateID::Still;
            break;
        case StateID::Interact:
            characterStateId = CharacterStateID::Interact;
            break;
        case StateID::Attack:
            characterStateId = CharacterStateID::Attack;
            break;
        case StateID::Pursuit:
            characterStateId = CharacterStateID::Move;
            break;
        case StateID::Meditate:
            characterStateId = CharacterStateID::Meditate;
            break;
        case StateID::TakeDrop:
            characterStateId =  CharacterStateID::Still;
            break;
        case StateID::Resurrect:
            characterStateId = CharacterStateID::Resurrect;
            break;
    }
    return characterStateId;
}
