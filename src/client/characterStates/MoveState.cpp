#include "MoveState.h"

MoveState::MoveState() : 
    CharacterState(CharacterStateID::Move){}

MoveState::~MoveState() {}

InputID MoveState::moveUp(Character& character){
    return InputID::up;
}

InputID MoveState::moveDown(Character& character) {
    return InputID::down;
}

InputID MoveState::moveLeft(Character& character) {
    return InputID::left;
}

InputID MoveState::moveRight(Character& character) {
    return InputID::right;
}

InputID MoveState::stopMove(Character& character) {
    return InputID::stopMove;
}
