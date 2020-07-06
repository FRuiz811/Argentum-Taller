#include "MoveState.h"

MoveState::MoveState() : 
    CharacterState(CharacterStateID::Move){}

MoveState::~MoveState() = default;

InputInfo MoveState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    if (character.getDirection() == Direction::up) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo MoveState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    if (character.getDirection() == Direction::down) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo MoveState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    if (character.getDirection() == Direction::left) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo MoveState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    if (character.getDirection() == Direction::right) 
        info.input = InputID::nothing;
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

InputInfo MoveState::selectItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo MoveState::selectTarget(Character& character, Point position) {
    InputInfo info;
    info.position = position;
    info.input =InputID::selectTarget;
    return info;
}

InputInfo MoveState::meditate(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo MoveState::resurrect(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo MoveState::cure(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo MoveState::takeItem(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo MoveState::dropItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::dropItem;
    info.aditional = item;
    return info;
}