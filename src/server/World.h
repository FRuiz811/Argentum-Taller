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

class World: public Thread {
private:
    TiledMap map;
    Board board;
    GameStatsConfig gameStatsConfig;
    std::unordered_map<uint, std::shared_ptr<GameObject>, std::hash<uint>> gameObjects;
    uint current_id;
    InputQueue inputQueue;
     std::atomic<bool> keepTalking;
    mutable std::mutex m;
    
    void addNPCs(std::vector<ObjectLayer> objectLayers);

public:
    explicit World(GameStatsConfig& configuration);

    uint getNextId();

    InputQueue& getInputQueue();

    TiledMap& getStaticMap();

    PlayerInfo createCharacter(RaceID race, GameClassID gameClass);

    virtual void run();

    void stop();

    virtual ~World();
};

#endif 
