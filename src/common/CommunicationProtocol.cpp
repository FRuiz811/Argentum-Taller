#include "CommunicationProtocol.h"
#include <arpa/inet.h>
#include <utility>
#include <iostream>

CommunicationProtocol::CommunicationProtocol() : socket() {}

CommunicationProtocol::CommunicationProtocol(Socket socket) : 
    socket(std::move(socket)) {}


void CommunicationProtocol::connect(const char* host, const char* port) {
    this->socket.connect(host,port);
}

void CommunicationProtocol::send(std::vector<uint8_t> msg) const {
    this->socket.send(msg.data(), msg.size());
}

Message CommunicationProtocol::recieve() const {
    uint8_t length[5];
    this->socket.recieve(&length, 5);
    uint32_t* temp32 = (uint32_t*) length;
	uint32_t length_message = ntohl(*temp32);
    uint8_t type = length[4];
    
    std::vector<uint8_t> buffer(length_message,0);
    uint8_t* buf = buffer.data();
    this->socket.recieve(buf, length_message);
    return std::move(Message(buffer,length_message,type));
}

void CommunicationProtocol::stop() {
    this->socket.shutdown(SHUT_RDWR);
    this->socket.close();
}

CommunicationProtocol::~CommunicationProtocol() = default;
