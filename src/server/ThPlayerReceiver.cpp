#include "ThPlayerReceiver.h"
#include <iostream>
#include <utility>
#include "../common/SocketException.h"

#define UNKNOW_ERROR "Unknow Error"
#define ERRORSOCKET "Error en la comunicación en ThPlayerReceiver::run() "
#define ERRORRECEIVER "Error en ThPlayerReceiver::run() "


ThPlayerReceiver::ThPlayerReceiver(std::shared_ptr<CommunicationProtocol> protocol, InputQueue& queue) :
    keepTalking(true), protocol(std::move(protocol)), queue(queue) {}

void ThPlayerReceiver::setId(uint id) {
    this->id = id;
}

void ThPlayerReceiver::run() {
    Message msg;
    InputInfo input;
    while(this->keepTalking) {
        try{
            msg = this->protocol->receive();
            input = Decoder::decodeCommand(msg);
            this->queue.push(std::move(input));
        } catch (const SocketException& e) {
            std::cerr << ERRORSOCKET << e.what() << std::endl;
            this->keepTalking = false;
        } catch(const std::exception& e){
            std::cerr << ERRORRECEIVER << e.what() << std::endl;
            this->keepTalking = false;
        }catch (...) {
            this->keepTalking = false;
            std::cerr << UNKNOW_ERROR << std::endl;
        }
    }
}

void ThPlayerReceiver::stop() {
    this->keepTalking = false;
}

ThPlayerReceiver::~ThPlayerReceiver() = default;