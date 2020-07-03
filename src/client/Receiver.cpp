#include "Receiver.h"
#include <vector>
#include <iostream>
#include "../common/Message.h"

Receiver::Receiver(CommunicationProtocol& protocol, DataQueue& queue) :
    queue(queue), keepTalking(false), protocol(std::move(protocol)) {}

void Receiver::run() {
    Message msg;
    try {
        //msg = this->protocol.recieve();
        this->queue.push(msg);
    } catch (...) {

    }
}

bool Receiver::is_alive() const {
    return this->keepTalking;
}

void Receiver::stop() {
    this->keepTalking = false;
}

Receiver::~Receiver() {}