#ifndef ARGENTUM_TALLER_WORLDINFO_H
#define ARGENTUM_TALLER_WORLDINFO_H


#include "../common/PlayerInfo.h"
#include "GameObject.h"

class WorldInfo {
private:
    PlayerInfo playerInfo;
    std::vector<GameObjectInfo> gameObjectsInfo;
    NPCInfo npcInfo;
public:
    WorldInfo(std::vector<std::shared_ptr<GameObject>> gameObjects, uint id);

    const PlayerInfo &getPlayerInfo() const;

    const std::vector<GameObjectInfo> &getGameObjectsInfo() const;

    const NPCInfo &getNpcInfo() const;

    virtual ~WorldInfo();

};


#endif //ARGENTUM_TALLER_WORLDINFO_H
