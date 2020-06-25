#include "DeadState.h"

DeadState::DeadState() : 
    CharacterState(CharacterStateID::Dead){}

DeadState::~DeadState() {}

InputInfo DeadState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::stopMove(Character& character) {
    InputInfo info;
    info.input = InputID::stopMove;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::selectItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo DeadState::selectTarget(Character& character, Point position) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}