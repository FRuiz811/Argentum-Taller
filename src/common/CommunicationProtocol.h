#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include <vector>
#include "../client/PlayerInfo.h"
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

    CommunicationProtocol(Socket socket);

    void connect(const char* host, const char* port);

    void send(std::vector<uint8_t> msg);

    Message recieve();

    ~CommunicationProtocol();
};

#endif
