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
    switch (item) {
    case 1:
        info.input = InputID::item1;
        break;
    case 2:
        info.input = InputID::item2;
        break;
    case 3:
        info.input = InputID::item3;
        break;
    case 4:
        info.input = InputID::item4;
        break;
    case 5:
        info.input = InputID::item5;
        break;
    case 6:
        info.input = InputID::item6;
        break;
    case 7:
        info.input = InputID::item7;
        break;
    case 8:
        info.input = InputID::item8;
        break;
    case 9:
        info.input = InputID::item9;
        break;
    default:
        info.input = InputID::nothing;
        break;
    }
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
