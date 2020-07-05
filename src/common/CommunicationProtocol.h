#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include <vector>
#include "PlayerInfo.h"
#include <cstdint>
#include "GameObjectInfo.h"
#include "../client/GameMap.h"
#include "Socket.h"
#include "Message.h"

//Este protocolo de comunicación está diseñado para enviar el mapa, la
//información del jugador, los objetos renderizables del mapa(items, criaturas, npc u otros jugadores)
// y los comandos que ingresa el jugador. 

class CommunicationProtocol {
private:
    Socket socket;
public:
    CommunicationProtocol();
    explicit CommunicationProtocol(Socket socket);

    CommunicationProtocol(CommunicationProtocol&& other) noexcept ;


    void connect(const char* host, const char* port);

    void send(std::vector<uint8_t> msg) const;

    Message receive() const;

    void stop();

    ~CommunicationProtocol();
};

#endif
