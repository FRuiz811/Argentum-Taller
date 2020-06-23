#include "MoveState.h"

MoveState::MoveState() : 
    CharacterState(CharacterStateID::Move){}

MoveState::~MoveState() {}

InputInfo MoveState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo MoveState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo MoveState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo MoveState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo MoveState::stopMove(Character& character) {
    InputInfo info;
    info.input = InputID::stopMove;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}
