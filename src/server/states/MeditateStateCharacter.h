#ifndef ARGENTUM_TALLER_MEDITATESTATECHARACTER_H
#define ARGENTUM_TALLER_MEDITATESTATECHARACTER_H


#include "StateCharacter.h"

class MeditateStateCharacter : public StateCharacter {
public:
    MeditateStateCharacter();

    ~MeditateStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isAttacking() override;

    bool isMeditating() override;

    void init(InputInfo aInputInfo) override;

};


#endif //ARGENTUM_TALLER_MEDITATESTATECHARACTER_H
