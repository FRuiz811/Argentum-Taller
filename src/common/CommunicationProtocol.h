#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include <vector>
#include "../client/PlayerInfo.h"
#include <cstdint>
#include "GameObjectInfo.h"

//Este protocolo de comunicación está diseñado para enviar el mapa, la
//información del jugador, los objetos renderizables del mapa(items, criaturas, npc u otros jugadores)
// y los comandos que ingresa el jugador. 

class CommunicationProtocol {
private:
    std::vector<uint8_t> encodeMsg;
    void encodeStatsPlayer(const PlayerInfo info);
    void encodeEquipmentPlayer(const PlayerInfo info);
    void encodeInventory(const PlayerInfo info);
    void encodeStatePlayer(const GameObjectInfo info);
    void conversorTo8(uint32_t value,int from);
    uint32_t conversorTo32(uint8_t* value);
    uint16_t conversorTo16(uint8_t* value);
    std::string decodeEquipment(uint8_t* idsEquipment,bool isGameObject=false);
    std::string decodeInventory(uint8_t* idsInventory);
    void encodeItem(GameObjectInfo object);
    void encodeCharacter(GameObjectInfo object);
public:
    CommunicationProtocol();
    //De un PlayerInfo genera una tira de bytes con la codificación correspondiente
    std::vector<uint8_t> encodePlayerInfo(const PlayerInfo info);

    std::vector<uint8_t> encodeGameObjects(const std::vector<GameObjectInfo> objects);
    //Se recibe como parámetro el mensaje recibido desde el servidor. Los primeros 5 bytes ya fueron
    //leidos y por lo tanto no serán pasados a esta función. Devuelve un PlayerInfo con toda la información
    //del jugador
    PlayerInfo decodePlayerInfo(std::vector<uint8_t> msg);

    std::vector<GameObjectInfo> decodeGameObjects(std::vector<uint8_t> msg);

    InputInfo decodeCommand(std::vector<uint8_t> msg);

    std::vector<uint8_t> encodeCommand(InputInfo input);

    std::vector<uint8_t> encodeInit(RaceID race, GameClassID gameClass);

    ~CommunicationProtocol();
};

#endif
