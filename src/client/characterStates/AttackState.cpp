#include "AttackState.h"

AttackState::AttackState() : 
    CharacterState(CharacterStateID::Attack){}

AttackState::~AttackState() {}

InputInfo AttackState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    if (character.getDirection() == Direction::up) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo AttackState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    if (character.getDirection() == Direction::down) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo AttackState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    if (character.getDirection() == Direction::left) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo AttackState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    if (character.getDirection() == Direction::right) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo AttackState::stopMove(Character& character) {
    InputInfo info;
    info.input = InputID::stopMove;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo AttackState::selectItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo AttackState::selectTarget(Character& character, Point position) {
    InputInfo info;
    info.position = position;
    info.input =InputID::selectTarget;
    return info;
}

InputInfo AttackState::meditate(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo AttackState::resurrect(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo AttackState::cure(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo AttackState::takeItem(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}