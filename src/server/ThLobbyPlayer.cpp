#include <iostream>
#include "ThLobbyPlayer.h"
#include "../common/Decoder.h"

#define INITMSG 0x04

void ThLobbyPlayer::run() {
    Message welcomeMsg = this->protocol.receive();
    std::shared_ptr<GameCharacter> aCharacter;
    if (welcomeMsg.getType() == INITMSG) {
        RaceID race = (RaceID) welcomeMsg.read8();
        GameClassID gameClass = (GameClassID) welcomeMsg.read8();
        aCharacter = world.createCharacter(race, gameClass);
    }
    std::vector<uint8_t> map = Decoder::encodeMap(this->world.getStaticMap());
    std::cout << map.size() << std::endl;
    this->protocol.send(map);
    this->protocol.send(Decoder::encodePlayerInfo(aCharacter->getPlayerInfo()));
    world.addPlayer(new ThPlayer(std::move(protocol), aCharacter));
    keepTalking = false;
}

ThLobbyPlayer::~ThLobbyPlayer() = default;

ThLobbyPlayer::ThLobbyPlayer(Socket socket, World &world) :
keepTalking(true), protocol(std::move(socket)), world(world) {}

void ThLobbyPlayer::stop() {
    this->keepTalking = false;
    this->protocol.stop();
}

bool ThLobbyPlayer::is_alive() const {
    return keepTalking;
}
