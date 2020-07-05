#include "Receiver.h"
#include <vector>
#include <iostream>
#include "../common/Message.h"

Receiver::Receiver(CommunicationProtocol& protocol, DataQueue& queue) :
    queue(queue), keepTalking(false), protocol(protocol) {}

void Receiver::run() {
    Message msg;
    while (this->keepTalking){
        try {
            msg = this->protocol.receive();
            this->queue.push(msg);
        }   catch (...) {

        }
    }
}

bool Receiver::is_alive() const {
    return this->keepTalking;
}

void Receiver::stop() {
    this->keepTalking = false;
}

Receiver::~Receiver() {}