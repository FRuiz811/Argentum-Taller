#include "ThPlayer.h"
#include <iostream>
#include <utility>
#include "../common/SocketException.h"

#define UNKNOW_ERROR "Unknow Error"
#define ERRORSOCKET "Error en la comunicaciónn en ThPlayer::run() "
#define ERRORDISPATCHER "Error en ThPlayer::run() "

ThPlayer::ThPlayer(const std::shared_ptr<CommunicationProtocol>& protocol, std::shared_ptr<GameCharacter> aCharacter) :
protocol(protocol), keepTalking(true), character(std::move(aCharacter)),
receiver(protocol, character->getQueueInputs()), worldInfoQueue(true) {}

void ThPlayer::run() {
    this->receiver.setId(character->getId());
    this->receiver.start();
    while (this->keepTalking) {
        try{
            WorldInfo worldInfo = worldInfoQueue.pop();
            const PlayerInfo& aPlayerInfo = worldInfo.getPlayerInfo();
            this->protocol->send(Decoder::encodePlayerInfo(aPlayerInfo));
            this->protocol->send(Decoder::encodeGameObjects(worldInfo.getGameObjectsInfo()));
            if (aPlayerInfo.getState() == CharacterStateID::Interact && worldInfo.getNpcInfo().type != 0) {
                this->protocol->send(Decoder::encodeNPCInfo(worldInfo.getNpcInfo()));
            }
            
        } catch(const SocketException& e) {
           std::cout << ERRORSOCKET << e.what() << std::endl;
           this->stop();
        } catch(const std::exception& e){
            std::cerr << ERRORDISPATCHER << e.what() << std::endl;
            this->stop();
        } catch (...) {
            std::cerr << UNKNOW_ERROR << std::endl;
            this->stop();
        }
    }
}

void ThPlayer::stop() {
    this->keepTalking = false;
    this->receiver.stop();
    this->receiver.join();
    this->protocol->stop();
}

bool ThPlayer::is_alive() const {
    return this->keepTalking;
}

void ThPlayer::update(const WorldInfo& worldInfo) {
    worldInfoQueue.push(worldInfo);
}

ThPlayer::~ThPlayer()= default;