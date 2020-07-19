#ifndef ARGENTUM_TALLER_STATE_H
#define ARGENTUM_TALLER_STATE_H

#include <GameObject.h>
#include "../../common/Identificators.h"

class State {
protected:
    bool finalized = false;
    InputInfo inputInfo;
    StateID stateId;
public:
    State();

    virtual ~State();

    StateID getStateId() const;

    const InputInfo &getInputInfo() const;

    bool isOver() const;

    virtual void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) = 0;

    virtual StateID getNextStateID(InputInfo aInputInfo) = 0;

    virtual StateID getResetStateID() = 0;

    virtual bool isAttacking() = 0;

    virtual void init(InputInfo aInputInfo) = 0;
};


#endif //ARGENTUM_TALLER_STATE_H
