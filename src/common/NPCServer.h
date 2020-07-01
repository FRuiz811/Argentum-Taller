#ifndef NPC_H
#define NPC_H

#include "GameObject.h"

class NPCServer : public GameObject{
private:
    //TODO agregar items que puedan tener ( unorded_map<Id, Precio>)
public:
	NPCServer(uint id, Point point, const std::string& type);

    virtual ~NPCServer();

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) override;
};

#endif
