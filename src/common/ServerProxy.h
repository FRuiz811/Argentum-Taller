#ifndef ARGENTUM_TALLER_SERVERPROXY_H
#define ARGENTUM_TALLER_SERVERPROXY_H

#include <map>
#include <vector>
#include "MapObject.h"
#include "ObjectLayer.h"
#include "GameCharacter.h"
#include "../client/PlayerInfo.h"
#include "Identificators.h"
#include "TiledMap.h"
#include "InputQueue.h"

class ServerProxy {
private:
    TiledMap tiledMap;
    std::vector<MapObject> collisionObjects;
    std::vector<MapObject> cities;
    std::map<uint, GameObject> gameObjects;
    InputQueue queueInputs;
    int width;
    int heigth;
    uint current_id;
    PlayerInfo player;

    void fillCollisionsObjects(std::vector<ObjectLayer>);
    uint getNextId();

public:
    ServerProxy();

    ~ServerProxy();

    TiledMap& getStaticMap();

    void sendInput(InputInfo input);

    PlayerInfo updateModel();

    PlayerInfo createCharacter(int race, int gameClass);
    bool characterMove(uint id, Direction direction);
};


#endif //ARGENTUM_TALLER_SERVERPROXY_H
