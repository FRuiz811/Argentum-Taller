#ifndef PROFESSION_H
#define PROFESSION_H

#include <vector>
#include "../common/Identificators.h"

class Profession {
protected:
    std::vector<ActionsProfessionID> actions;
    Profession() {}

    std::vector<ActionsProfessionID> getActions() const {
        return std::move(actions);
    }

    virtual NPCInfo getInfo(uint id) = 0;

    ~Profession(){}
};

#endif