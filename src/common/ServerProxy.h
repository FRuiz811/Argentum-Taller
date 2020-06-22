#ifndef ARGENTUM_TALLER_SERVERPROXY_H
#define ARGENTUM_TALLER_SERVERPROXY_H

#include <map>
#include <vector>
#include "MapObject.h"
#include "ObjectLayer.h"
#include "GameCharacter.h"
#include "../client/PlayerInfo.h"
#include "TiledMap.h"

class ServerProxy {
private:
    TiledMap tiledMap;
    std::vector<MapObject> collisionObjects;
    std::vector<MapObject> cities;
    std::map<uint, GameObject> gameObjects;
    int width;
    int heigth;
    uint current_id;

    void fillCollisionsObjects(std::vector<ObjectLayer>);
    uint getNextId();

public:
    ServerProxy();

    ~ServerProxy();

    TiledMap& getStaticMap();

    PlayerInfo createCharacter(int race, int gameClass);
    bool characterMove(uint id, int direction);
};


#endif //ARGENTUM_TALLER_SERVERPROXY_H
