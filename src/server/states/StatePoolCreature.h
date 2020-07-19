#ifndef ARGENTUM_TALLER_STATEPOOLCREATURE_H
#define ARGENTUM_TALLER_STATEPOOLCREATURE_H


#include "StatePool.h"
#include "StateCreature.h"

class StatePoolCreature : public StatePool {
private:
    std::shared_ptr<StateCreature> actualState;
    std::unordered_map<StateID, std::shared_ptr<StateCreature>, std::hash<StateID>> states;
public:
    explicit StatePoolCreature();

    void updateState(InputInfo aInputInfo) override;

    bool startChasing(uint pursuitId);

    std::shared_ptr<StateCreature> generateState(StateID stateId);

    ~StatePoolCreature() override;

    void changeState(StateID id, InputInfo aInputInfo) override;

    void setNextState(StateID id, InputInfo aInputInfo) override;
};


#endif //ARGENTUM_TALLER_STATEPOOLCREATURE_H
