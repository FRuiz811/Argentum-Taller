#include "ResurrectState.h"

ResurrectState::ResurrectState() : 
    CharacterState(CharacterStateID::Resurrect){}

ResurrectState::~ResurrectState() {}

InputInfo ResurrectState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo ResurrectState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo ResurrectState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo ResurrectState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo ResurrectState::stopMove(Character& character) {
    InputInfo info;
    info.input = InputID::nothing;
    Point aux(0.0,0.0);
    info.position = aux;
    return info;
}

InputInfo ResurrectState::selectItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    return info;
}

InputInfo ResurrectState::selectTarget(Character& character, Point position) {
    InputInfo info;
    info.position = position;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::meditate(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::resurrect(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::cure(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::takeItem(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::dropItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::buyItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::sellItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    return info;
}

InputInfo ResurrectState::retire(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    return info;
}

InputInfo ResurrectState::deposit(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    return info;
}

InputInfo ResurrectState::unequipItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    return info;
}

