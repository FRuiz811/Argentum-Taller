#ifndef ARGENTUM_TALLER_DECODER_H
#define ARGENTUM_TALLER_DECODER_H


#include <cstdint>
#include <vector>
#include "PlayerInfo.h"
#include "TiledMap.h"
#include "Message.h"

//Este protocolo binario de comunicación está diseñado para enviar el mapa, la
//información del jugador, los objetos renderizables del mapa(items, criaturas, npc u otros jugadores),
//la información del NPC con el que interactua y los comandos que ingresa el jugador.

class Decoder {
private:
    static void encodeStatsPlayer(const PlayerInfo &info, std::vector<uint8_t>&);
    static void encodeEquipmentPlayer(const PlayerInfo &info, std::vector<uint8_t>&);
    static void encodeInventory(const PlayerInfo &info, std::vector<uint8_t>&);
    static void encodeStatePlayer(const GameObjectInfo &info, std::vector<uint8_t>&);
    static void conversorTo8(uint32_t value, uint8_t from, std::vector<uint8_t>& encodeMsg);
    static std::string decodeEquipment(Message& msg, bool isGameObject=false);
    static std::string decodeInventory(Message& msg);
    static void encodeItem(GameObjectInfo object, std::vector<uint8_t>&);
    static void encodeCharacter(GameObjectInfo object, std::vector<uint8_t>&);
public:
    Decoder();
    //De un PlayerInfo genera una codificación correspondiente
    static std::vector<uint8_t> encodePlayerInfo(const PlayerInfo &info);

    static std::vector<uint8_t> encodeCommand(InputInfo input);

    static std::vector<uint8_t> encodeInit(RaceID race, GameClassID gameClass);

    static std::vector<uint8_t> encodeMap(const TiledMap&);

    static std::vector<uint8_t> encodeNPCInfo(const NPCInfo& info);

    static std::vector<uint8_t> encodeGameObjects(const std::vector<GameObjectInfo> &objects);

    //Se recibe como parámetro el mensaje recibido desde el servidor
    //Devuelve un PlayerInfo con toda la información del jugador
    static PlayerInfo decodePlayerInfo(Message msg);

    static InputInfo decodeCommand(Message msg);

    static std::vector<GameObjectInfo> decodeGameObjects(Message msg);

    static TiledMap decodeMap(Message msg);

    static NPCInfo decodeNPCInfo(Message msg);

    virtual ~Decoder();
};


#endif //ARGENTUM_TALLER_DECODER_H
