#include "AttackState.h"

AttackState::AttackState() : 
    CharacterState(CharacterStateID::Attack) , beforeInput(InputID::nothing) {}

AttackState::~AttackState() = default;

InputInfo AttackState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    if (character.getDirection() == Direction::up) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    if (character.getDirection() == Direction::down) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    if (character.getDirection() == Direction::left) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    if (character.getDirection() == Direction::right) 
        info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::stopMove(Character& character) {
    InputInfo info;
    info.input = InputID::stopMove;
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::selectItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::selectTarget(Character& character, Point position) {
    InputInfo info;
    info.position = position;
    info.input = InputID::selectTarget;
    if (beforeInput == info.input)
        info.input = InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::meditate(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::resurrect(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::cure(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::takeItem(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::dropItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::buyItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::sellItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::retire(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::deposit(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo AttackState::unequipItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    beforeInput = info.input;
    return info;
}
