#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
#include "State.h"

class NPCServer : public GameObject{
private:
    //TODO agregar items que puedan tener ( unorded_map<Id, Precio>)
    std::unique_ptr<State> state;
public:
	NPCServer(uint id, Point point, const std::string& type);

    virtual ~NPCServer();

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) override;

    CharacterStateID getStateId() override;
};

#endif
