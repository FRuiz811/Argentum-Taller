#include "ThPlayerReceiver.h"

ThPlayerReceiver::ThPlayerReceiver(CommunicationProtocol& protocol, InputQueue& queue) :
    keepTalking(true), protocol(protocol), queue(queue) {}

void ThPlayerReceiver::run(){

}

void ThPlayerReceiver::stop(){

}

ThPlayerReceiver::~ThPlayerReceiver() = default;