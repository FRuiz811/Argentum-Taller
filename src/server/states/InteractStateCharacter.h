#ifndef ARGENTUM_TALLER_INTERACTSTATECHARACTER_H
#define ARGENTUM_TALLER_INTERACTSTATECHARACTER_H

#include "State.h"

class InteractStateCharacter: public State {
public:
    InteractStateCharacter(const InputInfo &info);

    ~InteractStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                     GameStatsConfig &gameStatsConfig) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isAttacking() override;

};

#endif
