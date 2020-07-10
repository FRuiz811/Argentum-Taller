#include "NPCServer.h"

#include <utility>
#include "Banker.h"
#include "Merchant.h"
#include "Priest.h"
#include "states/StillStateCharacter.h"

NPCServer::~NPCServer() = default;

NPCServer::NPCServer(uint id, const std::string& type, Point initialPoint, std::shared_ptr<Cell> initialCell) :
    GameObject(id, initialPoint, std::move(initialCell)) {

    if (type == "banker") {
        textureHashId = "ht00|h00|b08|s00|w00";
        this->profession = Banker::getInstance();
    } else if (type == "merchant") {
        textureHashId = "ht00|h00|b09|s00|w00";
        this->profession = Merchant::getInstance();
    } else {
        textureHashId = "ht00|h05|b10|s00|w00";
        this->profession = Priest::getInstance();
    }
    state = std::unique_ptr<State>(new StillStateCharacter());
}

void NPCServer::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {}

NPCInfo NPCServer::interact(GameObject& character, InputInfo input) {
    NPCInfo info = this->profession->getInfo(character.getId());
    return info;
}

CharacterStateID NPCServer::getStateId() {
    return state->getStateId();
}

uint NPCServer::receiveDamage(float damage) {
    return 0;
}

bool NPCServer::isReadyToRemove() {
    return false;
}

bool NPCServer::isDead() {
    return false;
}

void NPCServer::remove(Board &board) {
    cell->free();
}


