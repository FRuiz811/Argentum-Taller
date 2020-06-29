#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include <vector>
#include "../client/PlayerInfo.h"
#include <cstdint>

class CommunicationProtocol {
private:
    std::vector<uint8_t> encodeMsg;
    void encodeStatsPlayer(const PlayerInfo info);
    void encodeEquipmentPlayer(const PlayerInfo info);
    void encodeInventory(const PlayerInfo info);
    void encodeStatePlayer(const PlayerInfo info);
    uint32_t conversorTo32(uint8_t* value);
    std::string decodeEquipment(uint8_t* idsEquipment);
public:
    CommunicationProtocol();

    std::vector<uint8_t> encodePlayerInfo(const PlayerInfo info);

    PlayerInfo decodePlayerInfo(std::vector<uint8_t> msg);

    ~CommunicationProtocol();
};

#endif
