#include "NPCServer.h"

NPCServer::~NPCServer() = default;

void NPCServer::update() {

}

NPCServer::NPCServer(uint id, Point point, std::string type) {
    position = Position(point, 25, 45);
    textureHashId = "ht00|h00|b08|s00|w00";
}