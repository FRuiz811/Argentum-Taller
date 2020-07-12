#ifndef PROFESSION_H
#define PROFESSION_H

#include <vector>
#include "../common/Identificators.h"
#include "GameObject.h"
#include "GameCharacter.h"

class Profession {
protected:
    std::vector<ActionsProfessionID> actions;
public:
    Profession() {}

    ~Profession(){}
    
    std::vector<ActionsProfessionID> getActions() const {
        return actions;
    }

    virtual void processInput(GameCharacter& character, InputInfo inputInfo) = 0;

    virtual NPCInfo getInfo(uint id) = 0;
};

#endif