#include "NPCServer.h"

NPCServer::~NPCServer() = default;

NPCServer::NPCServer(uint id, Point point, const std::string& type) : GameObject(id) {
    position = Position(point, 25, 45);
    if (type == "banker") {
        textureHashId = "ht00|h00|b08|s00|w00";
    } else if (type == "merchant") {
        textureHashId = "ht00|h00|b09|s00|w00";
    } else {
        textureHashId = "ht00|h05|b10|s00|w00";
    }
}

void NPCServer::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                       GameStatsConfig &gameStatsConfig) {

}


