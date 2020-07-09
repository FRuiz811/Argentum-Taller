#ifndef ARGENTUM_TALLER_STILLSTATECHARACTER_H
#define ARGENTUM_TALLER_STILLSTATECHARACTER_H

#include <memory>
#include <vector>
#include <unordered_map>
#include "State.h"
#include "../../common/PlayerStats.h"
#include "../GameObject.h"
#include "../../common/StaticObject.h"

class StillStateCharacter: public State {
private:
    int itemToChange{0};
public:
    explicit StillStateCharacter(InputInfo);

    ~StillStateCharacter() override;

    bool isOnPursuit(uint pursuitId) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isAttacking() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) override;

};


#endif //ARGENTUM_TALLER_STILLSTATECHARACTER_H
