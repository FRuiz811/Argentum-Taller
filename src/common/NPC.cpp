//#include "NPC.h"

#include "NPC.h"

NPC::~NPC() = default;

void NPC::update() {

}

NPC::NPC(uint id, Point point, std::string type) {
    position = Position(point, 25, 45);
}