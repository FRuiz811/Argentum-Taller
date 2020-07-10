#include "StillState.h"

StillState::StillState() : 
    CharacterState(CharacterStateID::Still){}

StillState::~StillState() {}

InputInfo StillState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo StillState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo StillState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo StillState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo StillState::stopMove(Character& character) {
    InputInfo info;
    info.input = InputID::stopMove;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo StillState::selectItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::equipItem;
    info.aditional = item;
    return info;
}


InputInfo StillState::selectTarget(Character& character, Point position) {
    InputInfo info;
    info.position = position;
    info.input =InputID::selectTarget;
    return info;
}

InputInfo StillState::meditate(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::meditate;
    return info;
}

InputInfo StillState::resurrect(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo StillState::cure(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo StillState::takeItem(Character& character) {
    InputInfo info;
    info.position = character.getPosition();
    info.input =InputID::takeItem;
    return info;
}

InputInfo StillState::dropItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::dropItem;
    info.aditional = item;
    return info;
}

InputInfo StillState::buyItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo StillState::sellItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo StillState::retire(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    return info;
}

InputInfo StillState::deposit(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    return info;
}