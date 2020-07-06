#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <unordered_map>
#include <mutex>
#include <atomic>
#include "../common/TiledMap.h"
#include "../common/Board.h"
#include "../common/GameObject.h"
#include "../common/GameStatsConfig.h"
#include "../common/ObjectLayer.h"
#include "../common/Thread.h"
#include "../common/InputQueue.h"
#include "../common/GameCharacter.h"
#include "ThPlayer.h"

class World: public Thread {
private:
    TiledMap map;
    Board board;
    GameStatsConfig gameStatsConfig;
    std::unordered_map<uint, std::shared_ptr<GameObject>, std::hash<uint>> gameObjects;
    uint current_id;
    std::atomic<bool> keepTalking;
    mutable std::mutex m;
    std::unordered_map<uint, ThPlayer*> players;
    
    void addNPCs(std::vector<ObjectLayer> objectLayers);
    std::vector<GameObjectInfo> getUpdatedGameObjects();

public:
    explicit World(GameStatsConfig& configuration);

    uint getNextId();

    TiledMap& getStaticMap();

    void addCreatures();

    void generateCreature();

    void update();

    std::shared_ptr<GameCharacter> createCharacter(RaceID race, GameClassID gameClass);

    virtual void run();

    void stop();

    void addPlayer(ThPlayer* aPlayer,uint id);

    void clearFinishedPlayers();

    virtual ~World();
};

#endif 
