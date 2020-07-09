#include "DeadState.h"

DeadState::DeadState() : 
    CharacterState(CharacterStateID::Dead){}

DeadState::~DeadState() {}

InputInfo DeadState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    if (character.getDirection() == Direction::up) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    if (character.getDirection() == Direction::down) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    if (character.getDirection() == Direction::left) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo DeadState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    if (character.getDirection() == Direction::right) 
        info.input = InputID::nothing;
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

InputInfo DeadState::meditate(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo DeadState::resurrect(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::resurrect;
    return info;
}

InputInfo DeadState::cure(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo DeadState::takeItem(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo DeadState::dropItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo DeadState::buyItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo DeadState::sellItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}
