#ifndef ARGENTUM_TALLER_STATEPOOLCREATURE_H
#define ARGENTUM_TALLER_STATEPOOLCREATURE_H


#include "StatePool.h"

class StatePoolCreature : public StatePool {
public:
    explicit StatePoolCreature();

    void updateState(InputInfo aInputInfo) override;

    ~StatePoolCreature() override;

    void setNextState(StateID id, InputInfo info);
};


#endif //ARGENTUM_TALLER_STATEPOOLCREATURE_H
