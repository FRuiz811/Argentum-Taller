#ifndef ARGENTUM_TALLER_TAKEANDDROPSTATECHARACTER_H
#define ARGENTUM_TALLER_TAKEANDDROPSTATECHARACTER_H


#include "StateCharacter.h"

class TakeAndDropStateCharacter : public StateCharacter {
public:
    explicit TakeAndDropStateCharacter();

    ~TakeAndDropStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isAttacking() override;

    void init(InputInfo aInputInfo) override;

    bool isMeditating() override;
};


#endif //ARGENTUM_TALLER_TAKEANDDROPSTATECHARACTER_H
