#ifndef ARGENTUM_TALLER_STATE_H
#define ARGENTUM_TALLER_STATE_H

#include <unordered_map>
#include <memory>
#include <vector>
#include "../../common/StaticObject.h"
#include "../GameObject.h"

class State {
protected:
    bool finalized = false;
    InputInfo inputInfo;
    StateID stateId;
public:
    State();

    explicit State(InputInfo);

    virtual ~State();

    StateID getStateId() const;

    virtual void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) = 0;

    bool isOver() const;

    virtual void init(InputInfo aInputInfo) = 0;

    virtual StateID getNextStateID(InputInfo aInputInfo) = 0;

    virtual StateID getResetStateID() = 0;

    virtual bool isOnPursuit(uint pursuitId) = 0;

    virtual bool isAttacking() = 0;

    virtual bool isMeditating() = 0;
};


#endif //ARGENTUM_TALLER_STATE_H
