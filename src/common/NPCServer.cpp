//#include "NPCServer.h"

#include "NPCServer.h"

NPCServer::~NPCServer() = default;

void NPCServer::update() {

}

NPCServer::NPCServer(uint id, Point point, std::string type) {
    position = Position(point, 25, 45);
}