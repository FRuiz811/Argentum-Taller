#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
#include "Profession.h"
#include "states/State.h"

class NPCServer : public GameObject{
private:
    Profession* profession;
    std::unique_ptr<State> state;
public:
	NPCServer(uint id, const std::string& type, Point initialPoint, std::shared_ptr<Cell> initialCell);

    virtual ~NPCServer();

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) override;

    CharacterStateID getStateId() override;

    uint receiveDamage(float damage, GameStatsConfig &gameStatsConfig) override;

    bool isDead() override;

    void remove(Board &board) override;

    bool isReadyToRemove() override;
};

#endif
