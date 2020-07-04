#include "ThPlayer.h"
#include <iostream>

#define INITMSG 0x04

ThPlayer::ThPlayer(Socket socket, World& world) : protocol(std::move(socket)),
    world(world), keepTalking(true), receiver(protocol, world.getInputQueue()), player() {}

void ThPlayer::run() {
    Message welcomeMsg = this->protocol.recieve();
    if (welcomeMsg.getType() == INITMSG) {
        RaceID race =  (RaceID) welcomeMsg.read8();
        GameClassID gameClass =  (GameClassID) welcomeMsg.read8();
        this->player = world.createCharacter(race, gameClass);
    }
    std::vector<uint8_t> map = Decoder::encodeMap(this->world.getStaticMap());
    std::cout << map.size() << std::endl;
    this->protocol.send(map);
    this->protocol.send(Decoder::encodePlayerInfo(this->player));
    this->receiver.setId(this->player.getId());
    this->receiver.start();
    //while (this->keepTalking) {

    //}

}

void ThPlayer::stop() {
    this->keepTalking = false;
    this->receiver.stop();
    this->protocol.stop();
}

bool ThPlayer::is_alive() const {
    return this->keepTalking;
}

ThPlayer::~ThPlayer()= default;