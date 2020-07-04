#ifndef ARGENTUM_TALLER_SERVERPROXY_H
#define ARGENTUM_TALLER_SERVERPROXY_H

#include <unordered_map>
#include <vector>
#include "StaticObject.h"
#include "ObjectLayer.h"
#include "GameCharacter.h"
#include "../client/PlayerInfo.h"
#include "Identificators.h"
#include "TiledMap.h"
#include "InputQueue.h"
#include "Board.h"
#include "GameStatsConfig.h"
#include "Creature.h"
#include <memory>

class ServerProxy {
private:
    TiledMap tiledMap;
    Board board;
    GameStatsConfig gameStatsConfig;
    std::unordered_map<uint, std::shared_ptr<GameObject>, std::hash<uint>> gameObjects;
    uint current_id = 0;

    uint getNextId();
public:
    ServerProxy();

    ~ServerProxy();

    TiledMap& getStaticMap();

    void sendInput(InputInfo input, uint id);

    PlayerInfo createCharacter(RaceID race, GameClassID gameClass);

    std::vector<GameObjectInfo> getUpdatedGameObjects();

    void update();

    PlayerInfo getUpdatedPlayerInfo(uint id);

    void addNPCs(std::vector<ObjectLayer> objectLayers);

    void addCreatures();

    void generateCreature();
};


#endif //ARGENTUM_TALLER_SERVERPROXY_H
