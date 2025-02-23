#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <unordered_map>
#include <mutex>
#include <atomic>
#include "../common/TiledMap.h"
#include "Board.h"
#include "GameObject.h"
#include "GameStatsConfig.h"
#include "../common/ObjectLayer.h"
#include "../common/Thread.h"
#include "../common/InputQueue.h"
#include "GameCharacter.h"
#include "ThPlayer.h"
#include "Banker.h"
#include "Merchant.h"
#include "Priest.h"
#include "GameObjectsContainer.h"


class World: public Thread {
private:
    TiledMap map;
    Board board;
    GameStatsConfig& gameStatsConfig;
    GameObjectsContainer gameObjectsContainer;
    std::atomic<uint> current_id;
    std::atomic<bool> keepTalking;
    mutable std::mutex m;
    std::unordered_map<uint, ThPlayer*> players;
    Banker* banker;
    Merchant* merchant;
    Priest* priest;
    
    void addNPCs(std::vector<ObjectLayer> objectLayers);

    uint getNextId();

    void addCreatures();

    void generateCreature();

    void generateItem(const DropItem &dropItem, const std::shared_ptr<Cell>& emptyCell);

    void clearFinishedPlayers();

    void removeCreaturesAndItems();

    void update();

    void checkDrops();
public:
    explicit World(GameStatsConfig& configuration);

    TiledMap& getStaticMap();

    std::shared_ptr<GameCharacter> createCharacter(RaceID race, GameClassID gameClass);

    virtual void run();

    void stop();

    void addPlayer(ThPlayer* aPlayer,uint id);

    virtual ~World();
};

#endif 
