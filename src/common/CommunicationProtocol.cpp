#include "CommunicationProtocol.h"
#include <arpa/inet.h>
#include <utility>
#include <iostream>

#define ZERO 0x00
#define MAPMSG 0x00
#define PLAYERINFOMSG 0x01
#define OBJECTSINFOMSG 0x02
#define COMMANDMSG 0x03
#define OBJECTLENGTH 27
#define PLAYERINFOLENGTH 70
#define ITEM 0x01
#define CHARACTER 0x00

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

void CommunicationProtocol::encodeStatePlayer(const GameObjectInfo info) {
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
    uint8_t* idPtr = (uint8_t*) &id;
    for (int i=0; i < 4; i++)
        this->encodeMsg.push_back(*(idPtr+i));
    encodeStatsPlayer(info);
    encodeEquipmentPlayer(info);
    encodeInventory(info);
    encodeStatePlayer(info);
    return std::move(encodeMsg);
}

std::string CommunicationProtocol::decodeEquipment(uint8_t* idsEquipment,bool isGameObject) {
    std::string equipment;
    uint8_t id;
    std::string temp;
    equipment += "ht";
    id = *(idsEquipment);
    temp = std::to_string(id);
    if (temp.size() == 1) 
        equipment += "0";
    equipment += temp + "|";
    equipment += "h";
    id = *(idsEquipment+1);
    temp = std::to_string(id);
    if (temp.size() == 1) 
        equipment += "0";
    equipment += temp + "|";
    equipment += "b";
    id = *(idsEquipment+2);
    temp = std::to_string(id);
    if (temp.size() == 1) 
        equipment += "0";
    equipment += temp + "|";
    equipment += "s";
    id = *(idsEquipment+3);
    temp = std::to_string(id);
    if (temp.size() == 1) 
        equipment += "0";
    equipment += temp + "|";
    equipment += "w";
    id = *(idsEquipment+4);
    temp = std::to_string(id);
    if (temp.size() == 1) 
        equipment += "0";
    equipment += temp;
    if(isGameObject) {
        equipment +="|i";
        id = *(idsEquipment+5);
        temp = std::to_string(id);
        if (temp.size() == 1) 
            equipment += "0";
        equipment += temp;
    }
    return std::move(equipment);
}

std::string CommunicationProtocol::decodeInventory(uint8_t* idsInventory) {
    std::string inventory;
    uint8_t id;
    std::string temp;
    for (int i=0; i<9;i++) {
        id = *(idsInventory+i);
        temp = std::to_string(id);
        if (temp.size() == 1) 
            inventory += "0";
        inventory += temp;
        if (i != 8)
            inventory += "|";
    }
    return std::move(inventory);
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
    std::string equipment = decodeEquipment(msg.data()+40,false);
    std::string inventory = decodeInventory(msg.data()+45);
    CharacterStateID state = (CharacterStateID) (ntohl(conversorTo32(msg.data()+59))); //54
    Direction dir = (Direction) (ntohl(conversorTo32(msg.data()+63))); //58
    uint32_t x = ntohl(conversorTo32(msg.data()+67)); //62
    uint32_t y = ntohl(conversorTo32(msg.data()+71)); //66
    PlayerInfo info(id, Point(x,y), gold, life, mana, equipment, dir,
        safeGold,maxLife,maxMana,exp,maxExp,level,inventory,state);
    return info;
}

void CommunicationProtocol::encodeItem(GameObjectInfo object) {
    this->encodeMsg.push_back(ITEM);
    uint8_t idHelmet = (uint8_t) object.getHelmetID();
    uint8_t idHead = (uint8_t) object.getHeadID();
    uint8_t idBody = (uint8_t) object.getBodyID();
    uint8_t idShield = (uint8_t) object.getShieldID();
    uint8_t idWeapon = (uint8_t) object.getWeaponID();
    uint8_t idItem = (uint8_t) object.getItemID();

    this->encodeMsg.push_back(idHelmet);
    this->encodeMsg.push_back(idHead);
    this->encodeMsg.push_back(idBody);
    this->encodeMsg.push_back(idShield);
    this->encodeMsg.push_back(idWeapon);
    this->encodeMsg.push_back(idItem);
    //Encodeo el estado y direccion del item con 0 dado que no me interesa su valor
    for (int i=0; i<8;i++){
        this->encodeMsg.push_back(ZERO);
    }

    uint32_t posX = htonl(object.getPoint().x);
    uint32_t posY = htonl(object.getPoint().y);
    uint8_t* posXptr = (uint8_t*) &posX;
    for(int i = 0; i<4; i++)
        this->encodeMsg.push_back(*(posXptr+i));
    uint8_t* posYptr = (uint8_t*) &posY;
    for(int i = 0; i<4; i++)
        this->encodeMsg.push_back(*(posYptr+i));
    
}   

void CommunicationProtocol::encodeCharacter(GameObjectInfo object) {
    this->encodeMsg.push_back(CHARACTER);
    uint8_t idHelmet = (uint8_t) object.getHelmetID();
    uint8_t idHead = (uint8_t) object.getHeadID();
    uint8_t idBody = (uint8_t) object.getBodyID();
    uint8_t idShield = (uint8_t) object.getShieldID();
    uint8_t idWeapon = (uint8_t) object.getWeaponID();

    this->encodeMsg.push_back(idHelmet);
    this->encodeMsg.push_back(idHead);
    this->encodeMsg.push_back(idBody);
    this->encodeMsg.push_back(idShield);
    this->encodeMsg.push_back(idWeapon);
    this->encodeMsg.push_back(ZERO); //Correspondiente al valor del item que no es

    encodeStatePlayer(object);
}

std::vector<uint8_t> CommunicationProtocol::encodeGameObjects(const std::vector<GameObjectInfo> objects) {
    this->encodeMsg.clear();
    uint32_t cantObjects = objects.size();
    uint32_t length = cantObjects * OBJECTLENGTH + 4;
    length = htonl(length);
    cantObjects = htonl(cantObjects);
    uint8_t type = OBJECTSINFOMSG;
    uint8_t* lengthPtr = (uint8_t*) &length;
    for (int i=0; i < 4; i++)
        this->encodeMsg.push_back(*(lengthPtr+i));
    this->encodeMsg.push_back(type);
    uint8_t* cantObjectsPtr = (uint8_t*) &cantObjects;
    for (int i=0; i < 4; i++)
        this->encodeMsg.push_back(*(cantObjectsPtr+i));
    uint32_t id;
    uint8_t* idPtr;
    for(auto& object: objects) {
        id = htonl(object.getId());
        idPtr = (uint8_t*) &id;
        for (int i=0; i < 4; i++)
            this->encodeMsg.push_back(*(idPtr+i));
        if(object.isItem()) {   
            encodeItem(object);
        } else {
            encodeCharacter(object);
        }
    }
    return std::move(this->encodeMsg);
}

std::vector<GameObjectInfo> CommunicationProtocol::decodeGameObjects(std::vector<uint8_t> msg) {
    std::vector<GameObjectInfo> objects;
    uint32_t cantObjects = ntohl(conversorTo32(msg.data()));
    uint32_t pos;
    std::string equipment;
    for (int i=0; i < cantObjects ; i++) {
        pos = i*OBJECTLENGTH;
        uint32_t id = ntohl(conversorTo32(msg.data()+4+pos));
        uint8_t type = *(msg.data()+8+pos);
        equipment = decodeEquipment(msg.data()+9+pos,true);
        CharacterStateID state = (CharacterStateID) (ntohl(conversorTo32(msg.data()+15+pos))); 
        Direction dir = (Direction) (ntohl(conversorTo32(msg.data()+19+pos)));
        uint32_t x = ntohl(conversorTo32(msg.data()+23+pos)); 
        int32_t y = ntohl(conversorTo32(msg.data()+27+pos));
        GameObjectInfo info(id,Point(x,y),equipment,dir,state,type);
        objects.push_back(info);
    }
    return std::move(objects);
}

CommunicationProtocol::~CommunicationProtocol() {}