#include "NPCServer.h"

NPCServer::~NPCServer() = default;

NPCServer::NPCServer(uint id, Point point, std::string type) : GameObject(id) {
    position = Position(point, 25, 45);
    textureHashId = "ht00|h00|b08|s00|w00";
}

void NPCServer::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                       GameStatsConfig &gameStatsConfig) {

}


