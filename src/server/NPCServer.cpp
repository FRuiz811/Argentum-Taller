#include "NPCServer.h"
#include "states/StillStateCharacter.h"

NPCServer::~NPCServer() = default;

NPCServer::NPCServer(uint id, Point point, const std::string& type) : GameObject(id) {
    boardPosition = BoardPosition(Position(point, 25, 45), 0, true);
    if (type == "banker") {
        textureHashId = "ht00|h00|b08|s00|w00";
    } else if (type == "merchant") {
        textureHashId = "ht00|h00|b09|s00|w00";
    } else {
        textureHashId = "ht00|h05|b10|s00|w00";
    }
    InputInfo anInputInfo;
    anInputInfo.input = InputID::nothing;
    state = std::unique_ptr<State>(new StillStateCharacter(anInputInfo));
}

void NPCServer::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                       GameStatsConfig &gameStatsConfig) {

}

CharacterStateID NPCServer::getStateId() {
    return state->getStateId();
}

uint NPCServer::receiveDamage(float damage, GameStatsConfig &gameStatsConfig) {
    return 0;
}


