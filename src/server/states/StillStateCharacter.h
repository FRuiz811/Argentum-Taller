#ifndef ARGENTUM_TALLER_STILLSTATECHARACTER_H
#define ARGENTUM_TALLER_STILLSTATECHARACTER_H

#include <memory>
#include <vector>
#include <unordered_map>
#include "State.h"
#include "../GameObject.h"
#include "../../common/StaticObject.h"

class StillStateCharacter: public State {
public:
    StillStateCharacter();

    explicit StillStateCharacter(InputInfo);

    ~StillStateCharacter() override;

    bool isOnPursuit(uint pursuitId) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isMeditating() override;

    bool isAttacking() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

};


#endif //ARGENTUM_TALLER_STILLSTATECHARACTER_H
