#ifndef ARGENTUM_TALLER_INTERACTSTATECHARACTER_H
#define ARGENTUM_TALLER_INTERACTSTATECHARACTER_H

#include "StateCharacter.h"

class InteractStateCharacter: public StateCharacter {
private:
    bool interacting = false;
    std::shared_ptr<GameObject> aNpc = nullptr;
public:
    InteractStateCharacter();

    ~InteractStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void init(InputInfo aInputInfo) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isMeditating() override;

    bool isAttacking() override;

};

#endif
