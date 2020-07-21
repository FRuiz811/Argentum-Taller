#include <memory>
#include "ThLobbyPlayer.h"

#define INITMSG 0x04

void ThLobbyPlayer::run() {
    Message welcomeMsg = this->protocol->receive();
    std::shared_ptr<GameCharacter> aCharacter;
    if (welcomeMsg.getType() == INITMSG) {
        auto race = (RaceID) welcomeMsg.read8();
        auto gameClass = (GameClassID) welcomeMsg.read8();
        aCharacter = world.createCharacter(race, gameClass);
    }
    std::vector<uint8_t> map = Decoder::encodeMap(this->world.getStaticMap());
    this->protocol->send(map);
    this->protocol->send(Decoder::encodePlayerInfo(aCharacter->getPlayerInfo()));
    world.addPlayer(new ThPlayer(protocol, aCharacter),aCharacter->getId());
    keepTalking = false;
}

ThLobbyPlayer::~ThLobbyPlayer() = default;

ThLobbyPlayer::ThLobbyPlayer(Socket socket, World &world) :
keepTalking(true), world(world) {
    protocol = std::make_shared<CommunicationProtocol>(std::move(socket));
}

void ThLobbyPlayer::stop() {
    this->keepTalking = false;
    this->protocol->stop();
}

bool ThLobbyPlayer::is_alive() const {
    return keepTalking;
}
