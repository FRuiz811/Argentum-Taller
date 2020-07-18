#include "InteractState.h"

InteractState::InteractState() : 
    CharacterState(CharacterStateID::Interact), beforeInput(InputID::nothing){}

InteractState::~InteractState() {}

InputInfo InteractState::moveUp(Character& character){
    InputInfo info;
    info.input = InputID::up;
    if (info.input == beforeInput) {
        info.input = InputID::nothing;
    }
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::moveDown(Character& character) {
    InputInfo info;
    info.input = InputID::down;
    if (info.input == beforeInput) {
        info.input = InputID::nothing;
    }
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::moveLeft(Character& character) {
    InputInfo info;
    info.input = InputID::left;
    if (info.input == beforeInput) {
        info.input = InputID::nothing;
    }
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::moveRight(Character& character) {
    InputInfo info;
    info.input = InputID::right;
    if (info.input == beforeInput) {
        info.input = InputID::nothing;
    }
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::stopMove(Character& character) {
    InputInfo info;
    info.input = InputID::stopMove;
    Point aux(0.0,0.0);
    info.position = aux;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::selectItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::selectTarget(Character& character, Point position) {
    InputInfo info;
    info.position = position;
    info.input =InputID::selectTarget;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::meditate(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::resurrect(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::resurrect;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::cure(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::cure;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::takeItem(Character& character) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::dropItem(Character& character, int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::nothing;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::buyItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::buy;
    info.aditional = item;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::sellItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input =InputID::sell;
    info.aditional = item;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::deposit(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    if (isItem) {
        info.input =InputID::depositItem;
    } else {
        info.input =InputID::depositGold;
    }
    info.aditional = item;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::retire(Character& character,int item, bool isItem) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    if (isItem) {
        info.input =InputID::retireItem;
    } else {
        info.input =InputID::retireGold;
    }
    info.aditional = item;
    beforeInput = info.input;
    return info;
}

InputInfo InteractState::unequipItem(Character& character,int item) {
    InputInfo info;
    Point aux(0.0,0.0);
    info.position = aux;
    info.input = InputID::nothing;
    beforeInput = info.input;
    return info;
}

