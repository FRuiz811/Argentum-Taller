#include "WorldInfo.h"
#include "GameCharacter.h"

WorldInfo::~WorldInfo() = default;

WorldInfo::WorldInfo(std::vector<std::shared_ptr<GameObject>> gameObjects, uint id) :
    playerInfo(), gameObjectsInfo(), npcInfo(){
    std::vector<std::shared_ptr<GameObject>>::iterator iter;
    iter = gameObjects.begin();
    while (iter != gameObjects.end()){
        if ((*iter)->getId() == id) {
            this->npcInfo = (*iter)->getInteractInfo();
            this->playerInfo = (*iter)->getPlayerInfo();
            iter = gameObjects.erase(iter);
        } else {
            this->gameObjectsInfo.push_back((*iter)->getGameObjectInfo());
            iter++;
        }
    }
}

const PlayerInfo &WorldInfo::getPlayerInfo() const {
    return playerInfo;
}

const std::vector<GameObjectInfo> &WorldInfo::getGameObjectsInfo() const {
    return gameObjectsInfo;
}

const NPCInfo &WorldInfo::getNpcInfo() const {
    return npcInfo;
}
