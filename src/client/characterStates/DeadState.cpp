#include "DeadState.h"

DeadState::DeadState() : 
    CharacterState(CharacterStateID::Dead){}

DeadState::~DeadState() {}

InputID DeadState::moveUp(Character& character){
    return InputID::up;
}

InputID DeadState::moveDown(Character& character) {
    return InputID::down;
}

InputID DeadState::moveLeft(Character& character) {
    return InputID::left;
}

InputID DeadState::moveRight(Character& character) {
    return InputID::right;
}

InputID DeadState::stopMove(Character& character) {
    return InputID::stopMove;
}
