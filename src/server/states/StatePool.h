#ifndef ARGENTUM_TALLER_STATEPOOL_H
#define ARGENTUM_TALLER_STATEPOOL_H

#include "State.h"

class StatePool {
protected:
    std::shared_ptr<State> actualState;
    std::unordered_map<StateID, std::shared_ptr<State>, std::hash<StateID>> states;
public:
    explicit StatePool(std::shared_ptr<State> firstState);

    const std::shared_ptr<State> &getActualState() const;

    StateID getStateId();

    virtual void updateState(InputInfo aInputInfo) = 0;

    virtual ~StatePool();
};

#endif //ARGENTUM_TALLER_STATEPOOL_H
