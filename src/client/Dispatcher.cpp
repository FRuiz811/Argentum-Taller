#include "Dispatcher.h"
#include <vector>
#include <iostream>
#include "../common/SocketException.h"
#include "../common/Decoder.h"

Dispatcher::Dispatcher(CommunicationProtocol& protocol, InputQueue& queue) :
    queue(queue), keepTalking(true), protocol(protocol) {}

void Dispatcher::run() {
    InputInfo info;
    std::vector<uint8_t> msg;
    while (this->keepTalking) {
        try{
            info = this->queue.pop();
            msg = Decoder::encodeCommand(info);
            this->protocol.send(msg);
        } catch (const SocketException& e) {
            std::cerr << "Error en Dispatcher::run()" << e.what() << std::endl;
            this->keepTalking = false;
        } 

    }
}

bool Dispatcher::is_alive() const {
    return this->keepTalking;
}

void Dispatcher::stop() {
    this->keepTalking = false;
    this->protocol.stop();
}

Dispatcher::~Dispatcher() {}