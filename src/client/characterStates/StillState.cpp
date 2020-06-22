#include "StillState.h"

StillState::StillState() : 
    CharacterState(CharacterStateID::Still){}

StillState::~StillState() {}

InputID StillState::moveUp(Character& character){
    return InputID::up;
}

InputID StillState::moveDown(Character& character) {
    return InputID::down;
}

InputID StillState::moveLeft(Character& character) {
    return InputID::left;
}

InputID StillState::moveRight(Character& character) {
    return InputID::right;
}

InputID StillState::stopMove(Character& character) {
    return InputID::stopMove;
}
