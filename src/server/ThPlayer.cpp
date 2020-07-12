#include "ThPlayer.h"
#include <iostream>
#include <utility>
#include "../common/SocketException.h"

#define UNKNOW_ERROR "Unknow Error"
#define ERRORSOCKET "Error en la comunicaciónn en ThPlayer::run() "
#define ERRORDISPATCHER "Error en ThPlayer::run() "

ThPlayer::ThPlayer(const std::shared_ptr<CommunicationProtocol>& protocol, std::shared_ptr<GameCharacter> aCharacter) :
protocol(protocol), keepTalking(true), character(std::move(aCharacter)),
receiver(protocol, character->getQueueInputs()) {}

void ThPlayer::run() {
    this->receiver.setId(character->getId());
    this->receiver.start();
    while (this->keepTalking) {
        try{
            std::unique_lock<std::mutex> lock(m);
            if (canUpdate) {
                this->protocol->send(Decoder::encodePlayerInfo(character->getPlayerInfo()));
                this->protocol->send(Decoder::encodeGameObjects(gameObjectsInfo));
                if (this->character->getStateId() == CharacterStateID::Interact && this->interacting.type != 0) {
                    this->protocol->send(Decoder::encodeNPCInfo(interacting));
                }
                canUpdate = false;
            } else {
                cv.wait(lock);  
            }
        } catch(const SocketException& e) {
           std::cout << ERRORSOCKET << e.what() << std::endl;
           this->stop();
           
        } catch(const std::exception& e){
            std::cerr << ERRORDISPATCHER << e.what() << std::endl;
            this->keepTalking = false;
        } catch (...) {
            this->keepTalking = false;
            std::cerr << UNKNOW_ERROR << std::endl;
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

void ThPlayer::update(std::vector<std::shared_ptr<GameObject>> gameObject) {
    canUpdate = true;
    this->gameObjectsInfo.clear();
    std::vector<std::shared_ptr<GameObject>>::iterator iter;
    iter = gameObject.begin();
    while (iter != gameObject.end()){
        if ((*iter)->getId() == character->getId()){
            this->interacting = (*iter)->getInteractInfo();
            iter = gameObject.erase(iter);
        } else {
            this->gameObjectsInfo.push_back((*iter)->getGameObjectInfo());
            iter++;
        }
    }
    cv.notify_all();
}

ThPlayer::~ThPlayer()= default;