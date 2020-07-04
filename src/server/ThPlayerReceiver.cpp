#include "ThPlayerReceiver.h"
#include "../common/Message.h"
#include "../common/Decoder.h"

ThPlayerReceiver::ThPlayerReceiver(CommunicationProtocol& protocol, InputQueue& queue) :
    keepTalking(true), protocol(protocol), queue(queue) {}

void ThPlayerReceiver::setId(uint id) {
    this->id = id;
}


void ThPlayerReceiver::run() {
    Message msg;
    InputInfo input;
    while(this->keepTalking) {
        msg = this->protocol.recieve();
        input = Decoder::decodeCommand(msg);

        this->queue.push(std::move(input));
    }
}

void ThPlayerReceiver::stop() {
    this->keepTalking = false;
}

ThPlayerReceiver::~ThPlayerReceiver() {}