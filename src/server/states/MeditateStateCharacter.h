#ifndef ARGENTUM_TALLER_MEDITATESTATECHARACTER_H
#define ARGENTUM_TALLER_MEDITATESTATECHARACTER_H


#include "State.h"

class MeditateStateCharacter : public State {
public:
    MeditateStateCharacter();

    ~MeditateStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isAttacking() override;

};


#endif //ARGENTUM_TALLER_MEDITATESTATECHARACTER_H
