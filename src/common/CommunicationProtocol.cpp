#include "CommunicationProtocol.h"
#include <arpa/inet.h>
#include <utility>

#define PLAYERINFOMSG 0x01
#define PLAYERINFOLENGTH 70

CommunicationProtocol::CommunicationProtocol() {}

uint32_t CommunicationProtocol::conversorTo32(uint8_t* value){
    uint8_t temp[4];
	uint32_t* temp32;
    for (int j = 0; j < 4; j++) {
		temp[j] = value[j];
	}
    temp32 = (uint32_t*) temp;		
	return *temp32;
}

void CommunicationProtocol::encodeStatsPlayer(const PlayerInfo info) {
    uint32_t life,maxLife, mana, maxMana,exp, maxExp, level, gold, safeGold;
    life = htonl(info.getLife());
    maxLife = htonl(info.getMaxLife());
    mana = htonl(info.getMana());
    maxMana = htonl(info.getMaxMana());
    exp = htonl(info.getExp());
    maxExp = htonl(info.getMaxExp());
    level = htonl(info.getLevel());
    gold = htonl(info.getGoldAmount()); 
    safeGold = htonl(info.getSafeGold());
    uint8_t* lifePtr = (uint8_t*) &life;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(lifePtr+i));
    }
    uint8_t* maxLifePtr = (uint8_t*) &maxLife;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(maxLifePtr+i));
    }
    uint8_t* manaPtr = (uint8_t*) &mana;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(manaPtr+i));
    }
     uint8_t* maxManaPtr = (uint8_t*) &maxMana;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(maxManaPtr+i));
    }
     uint8_t* expPtr = (uint8_t*) &exp;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(expPtr+i));
    }
     uint8_t* maxExpPtr = (uint8_t*) &maxExp;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(maxExpPtr+i));
    }
     uint8_t* levelPtr = (uint8_t*) &level;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(levelPtr+i));
    }
    uint8_t* goldPtr = (uint8_t*) &gold;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(goldPtr+i));
    }
    uint8_t* safeGoldPtr = (uint8_t*) &safeGold;
    for(int i = 0; i < 4; i++) {
        this->encodeMsg.push_back(*(safeGoldPtr+i));
    }
}

void CommunicationProtocol::encodeInventory(const PlayerInfo info) {
    std::string inventory = info.getInventory();
    std::string item;
    uint8_t idItem;
    for (int i = 0; i<9; i++) {
        item = inventory.substr(2*i+i,2);
        idItem = std::stoi(item);
        this->encodeMsg.push_back(idItem);
    }
}

void CommunicationProtocol::encodeEquipmentPlayer(const PlayerInfo info) {
    uint8_t idHelmet = (uint8_t) info.getHelmetID();
    uint8_t idHead = (uint8_t) info.getHeadID();
    uint8_t idBody = (uint8_t) info.getBodyID();
    uint8_t idShield = (uint8_t) info.getShieldID();
    uint8_t idWeapon = (uint8_t) info.getWeaponID();

    this->encodeMsg.push_back(idHelmet);
    this->encodeMsg.push_back(idHead);
    this->encodeMsg.push_back(idBody);
    this->encodeMsg.push_back(idShield);
    this->encodeMsg.push_back(idWeapon);
}

void CommunicationProtocol::encodeStatePlayer(const PlayerInfo info) {
    uint32_t state = htonl((uint32_t) info.getState());
    uint32_t dir = htonl((uint32_t) info.getDirection());
    uint32_t posX = htonl(info.getPoint().x);
    uint32_t posY = htonl(info.getPoint().y);

    uint8_t* statePtr = (uint8_t*) &state;
    for(int i = 0; i<4; i++)
        this->encodeMsg.push_back(*(statePtr+i));
    uint8_t* dirPtr = (uint8_t*) &dir;
    for(int i = 0; i<4; i++)
        this->encodeMsg.push_back(*(dirPtr+i));
    uint8_t* posXptr = (uint8_t*) &posX;
    for(int i = 0; i<4; i++)
        this->encodeMsg.push_back(*(posXptr+i));
    uint8_t* posYptr = (uint8_t*) &posY;
    for(int i = 0; i<4; i++)
        this->encodeMsg.push_back(*(posYptr+i));
}

std::vector<uint8_t> CommunicationProtocol::encodePlayerInfo(const PlayerInfo info) {
    this->encodeMsg.clear();
    uint32_t length = PLAYERINFOLENGTH;
    //Hago lugar para lo que será la longitud del mensaje
    length = htonl(length);
    uint8_t* lengthPtr = (uint8_t*) &length;
    for (int i=0; i < 4; i++)
        this->encodeMsg.push_back(*(lengthPtr+i));
    uint8_t type = PLAYERINFOMSG;
    this->encodeMsg.push_back(type);
    uint32_t id = info.getId();
    id = htonl(id);
    uint8_t* idPtr = (uint8_t*) &idPtr;
    for (int i=0; i < 4; i++)
        this->encodeMsg.push_back(*(idPtr+i));
    encodeStatsPlayer(info);
    encodeEquipmentPlayer(info);
    encodeInventory(info);
    encodeStatePlayer(info);
    return std::move(encodeMsg);
}


std::string CommunicationProtocol::decodeEquipment(uint8_t* idsEquipment) {
    std::string equipment;
    uint8_t id;
    return std::move(equipment);
}
PlayerInfo CommunicationProtocol::decodePlayerInfo(std::vector<uint8_t> msg) {
    uint32_t id = ntohl(conversorTo32(msg.data()));
    uint32_t life = ntohl(conversorTo32(msg.data()+4));
    uint32_t maxLife = ntohl(conversorTo32(msg.data()+8));
    uint32_t mana = ntohl(conversorTo32(msg.data()+12));
    uint32_t maxMana = ntohl(conversorTo32(msg.data()+16));
    uint32_t exp = ntohl(conversorTo32(msg.data()+20));
    uint32_t maxExp = ntohl(conversorTo32(msg.data()+24));
    uint32_t level = ntohl(conversorTo32(msg.data()+28));
    uint32_t gold = ntohl(conversorTo32(msg.data()+32));
    uint32_t safeGold = ntohl(conversorTo32(msg.data()+36));
    std::string equipment = decodeEquipment(msg.data()+40);
    PlayerInfo info(id, Point(0,0), gold, life, mana, "", Direction::right,
        safeGold,maxLife,maxMana,exp,maxExp,level,"",CharacterStateID::Still);
    return info;
}

CommunicationProtocol::~CommunicationProtocol() {}