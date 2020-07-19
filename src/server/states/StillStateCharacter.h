#ifndef ARGENTUM_TALLER_STILLSTATECHARACTER_H
#define ARGENTUM_TALLER_STILLSTATECHARACTER_H

#include "StateCharacter.h"

class StillStateCharacter: public StateCharacter {
public:
    StillStateCharacter();

    ~StillStateCharacter() override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    void init(InputInfo aInputInfo) override;

    bool isMeditating() override;

    bool isAttacking() override;

    void init(InputInfo aInputInfo) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

};


#endif //ARGENTUM_TALLER_STILLSTATECHARACTER_H
