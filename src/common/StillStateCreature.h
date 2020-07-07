#ifndef ARGENTUM_TALLER_STILLSTATECREATURE_H
#define ARGENTUM_TALLER_STILLSTATECREATURE_H

#include "State.h"

class StillStateCreature : public State {
private:
public:
    StillStateCreature();

    virtual ~StillStateCreature();

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                     GameStatsConfig &gameStatsConfig) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

};


#endif //ARGENTUM_TALLER_STILLSTATECREATURE_H
