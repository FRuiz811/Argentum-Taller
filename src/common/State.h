#ifndef ARGENTUM_TALLER_STATE_H
#define ARGENTUM_TALLER_STATE_H

#include <unordered_map>
#include <memory>
#include <vector>
#include "PlayerStats.h"
#include "StaticObject.h"
#include "GameObject.h"

class State {
protected:
    bool finalized = false;
    std::unique_ptr<State> nextState = nullptr;
    InputInfo inputInfo;
    CharacterStateID stateId;
public:
    State();

    explicit State(InputInfo);

    virtual ~State();

    CharacterStateID getStateId() const;

    virtual void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) = 0;

    bool isOver() const;

    virtual void setNextState(InputInfo) = 0;

    virtual void resetState() = 0;

    std::unique_ptr<State> getNextState();

    bool hasNextState();
};


#endif //ARGENTUM_TALLER_STATE_H
