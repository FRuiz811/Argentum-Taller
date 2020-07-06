#ifndef ARGENTUM_TALLER_PURSUITSTATECREATURE_H
#define ARGENTUM_TALLER_PURSUITSTATECREATURE_H


#include "State.h"

class PursuitStateCreature : public State {
private:
    uint pursuitId;
public:
    explicit PursuitStateCreature(uint id);

    ~PursuitStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                     GameStatsConfig &gameStatsConfig) override;

    void setNextState(InputInfo info) override;

    void resetState() override;
};


#endif //ARGENTUM_TALLER_PURSUITSTATECREATURE_H
