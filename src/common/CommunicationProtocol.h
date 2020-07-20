#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include <vector>
#include "PlayerInfo.h"
#include <cstdint>
#include "GameObjectInfo.h"
#include "../client/GameMap.h"
#include "Socket.h"
#include "Message.h"

//Wrapper del socket utilizado para la comunicacion.s
class CommunicationProtocol {
private:
    Socket socket;
public:
    CommunicationProtocol();
    explicit CommunicationProtocol(Socket socket);

    void connect(const char* host, const char* port);

    void send(std::vector<uint8_t> msg) const;

    Message receive() const;

    void stop();

    ~CommunicationProtocol();
};

#endif
