#include "CommunicationProtocol.h"
#include <arpa/inet.h>
#include <utility>
#include <iostream>


CommunicationProtocol::CommunicationProtocol() = default;



CommunicationProtocol::~CommunicationProtocol() = default;

void CommunicationProtocol::send(std::vector<uint8_t>) {

}

Message CommunicationProtocol::recv() {
    return Message();
}
