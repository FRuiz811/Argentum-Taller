#include "StartMovingState.h"

StartMovingState::StartMovingState() : 
    CharacterState(CharacterStateID::StartMoving){}

StartMovingState::~StartMovingState() {}

InputID StartMovingState::moveUp(Character& character){
    return InputID::up;
}

InputID StartMovingState::moveDown(Character& character) {
    return InputID::down;
}

InputID StartMovingState::moveLeft(Character& character) {
    return InputID::left;
}

InputID StartMovingState::moveRight(Character& character) {
    return InputID::right;
}

InputID StartMovingState::stopMove(Character& character) {
    return InputID::stopMove;
}
