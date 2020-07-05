#include "ThPlayer.h"
#include <iostream>
#include <utility>



ThPlayer::ThPlayer(CommunicationProtocol protocol, std::shared_ptr<GameCharacter> aCharacter) :
protocol(std::move(protocol)), keepTalking(true), character(std::move(aCharacter)), receiver(protocol, character->getQueueInputs()) {}

void ThPlayer::run() {
    this->receiver.setId(character->getId());
    this->receiver.start();
    while (this->keepTalking) {
        if (canUpdate) {
            this->protocol.send(Decoder::encodePlayerInfo(character->getPlayerInfo()));
            this->protocol.send(Decoder::encodeGameObjects(gameObjectsInfo));
            canUpdate = false;
        }
    }
}

void ThPlayer::stop() {
    this->keepTalking = false;
    this->receiver.stop();
    this->protocol.stop();
}

bool ThPlayer::is_alive() const {
    return this->keepTalking;
}

void ThPlayer::update(std::vector<GameObjectInfo> gameObjectInfo) {
    canUpdate = true;
    std::vector<GameObjectInfo>::iterator iter;
    iter = gameObjectInfo.begin();
    while (iter != gameObjectInfo.end()){
        if ((*iter).getId() == character->getId()){
            iter = gameObjectInfo.erase(iter);
        } else {
            iter++;
        }
    }
}

ThPlayer::~ThPlayer()= default;