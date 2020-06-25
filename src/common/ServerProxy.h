#ifndef ARGENTUM_TALLER_SERVERPROXY_H
#define ARGENTUM_TALLER_SERVERPROXY_H

#include <unordered_map>
#include <vector>
#include "StaticObject.h"
#include "ObjectLayer.h"
#include "GameCharacter.h"
#include "../client/PlayerInfo.h"
#include "TiledMap.h"
#include <memory>

class ServerProxy {
private:
    TiledMap tiledMap;
    std::vector<StaticObject> collisionObjects;
    std::vector<StaticObject> cities;
    std::unordered_map<uint, std::shared_ptr<GameObject>, std::hash<uint>> gameObjects;
    int width;
    int heigth;
    uint current_id;
    Point initialPoint;

    void fillCollisionsObjects(std::vector<ObjectLayer>);
    uint getNextId();

public:
    ServerProxy();

    ~ServerProxy();

    TiledMap& getStaticMap();

    PlayerInfo createCharacter(int race, int gameClass);
    bool characterMove(uint id, int direction);
    std::vector<GameObjectInfo> getUpdatedGameObjects();
    void update();
};


#endif //ARGENTUM_TALLER_SERVERPROXY_H
