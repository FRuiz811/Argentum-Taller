#include "Receiver.h"
#include <vector>
#include <iostream>
#include "../common/Message.h"
#include "../common/SocketException.h"

Receiver::Receiver(CommunicationProtocol& protocol, DataQueue& queue) :
    queue(queue), keepTalking(false), protocol(protocol) {}

void Receiver::run() {
    Message msg;
    while (this->keepTalking){
        try {
            msg = this->protocol.recieve();
            this->queue.push(msg);
        }  catch (const SocketException& e) {
            std::cerr << "Error en Receiver::run()" << e.what() << std::endl;
            this->keepTalking = false;
        } 
    }
}

bool Receiver::is_alive() const {
    return this->keepTalking;
}

void Receiver::stop() {
    this->keepTalking = false;
    this->protocol.stop();
}

Receiver::~Receiver() {}