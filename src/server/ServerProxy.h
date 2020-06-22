#ifndef ARGENTUM_TALLER_SERVERPROXY_H
#define ARGENTUM_TALLER_SERVERPROXY_H


#include <unordered_map>
#include <vector>
#include "../client/MapObject.h"
#include "Cell.h"
#include "../client/ObjectLayer.h"
#include "City.h"
#include "Character.h"
#include "../client/GameMap.h"

class ServerProxy {
private:
    TiledMap tiledMap;
    std::vector<MapObject> collisionObjects;
    std::vector<MapObject> cities;
    std::unordered_map<uint, GameObject,
    std::hash<uint>> gameObjects;
    int width;
    int heigth;
    static unsigned int current_id;

    void fillCollisionsObjects(const std::vector<ObjectLayer> &vector);
    unsigned int getNextId();

public:
    ServerProxy();

    ~ServerProxy();

    TiledMap& getStaticMap();

    uint createCharacter(int race, int gameClass);
    bool characterMove(uint id);
    std::unordered_map<uint, GameObject,
    std::hash<uint>> getGameObjects();
};


#endif //ARGENTUM_TALLER_SERVERPROXY_H
