#include "Dispatcher.h"
#include <vector>
#include <iostream>
#include "../common/Decoder.h"

Dispatcher::Dispatcher(CommunicationProtocol& protocol, InputQueue& queue) :
    queue(queue), keepTalking(false), protocol(protocol) {}

void Dispatcher::run() {
    InputInfo info;
    std::vector<uint8_t> msg;
    while (this->keepTalking) {
        try{
            info = this->queue.pop();
            msg = Decoder::encodeCommand(info);
            this->protocol.send(msg);
        } catch (const std::exception& e) {
            this->keepTalking = false;
            std::cerr << "Error en Dispatcher::run()" << e.what() << std::endl;
        } 

    }
}

bool Dispatcher::is_alive() const {
    return this->keepTalking;
}

void Dispatcher::stop() {
    this->keepTalking = false;
}

Dispatcher::~Dispatcher() {}