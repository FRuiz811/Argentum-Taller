#include "CommunicationProtocol.h"
#include <arpa/inet.h>
#include <utility>
#include <iostream>

#define ZERO 0x00
#define MAPMSG 0x00
#define PLAYERINFOMSG 0x01
#define OBJECTSINFOMSG 0x02
#define COMMANDMSG 0x03
#define INITMSG 0x04
#define INITLENGTH 2
#define OBJECTLENGTH 17
#define PLAYERINFOLENGTH 44
#define COMMANDLENGTH 7
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

uint16_t CommunicationProtocol::conversorTo16(uint8_t* value){
    uint8_t temp[4];
	uint16_t* temp16;
    for (int j = 0; j < 2; j++) {
		temp[j] = value[j];
	}
    temp16 = (uint16_t*) temp;		
	return *temp16;
}

void CommunicationProtocol::conversorTo8(uint32_t value, int from) {
    int max;
    if (from ==16) {
        max = 2;
    } else if (from == 32) {
        max = 4;
    }
    uint8_t* ptr = (uint8_t*) &value;
    for(int i = 0; i < max; i++)
        this->encodeMsg.push_back(*(ptr+i));
}

void CommunicationProtocol::encodeStatsPlayer(const PlayerInfo info) {
    uint16_t life,maxLife, mana, maxMana, level, gold, safeGold;
    uint32_t maxExp, exp;
    life = htons(info.getLife());
    maxLife = htons(info.getMaxLife());
    mana = htons(info.getMana());
    maxMana = htons(info.getMaxMana());
    exp = htonl(info.getExp());
    maxExp = htonl(info.getMaxExp());
    level = htons(info.getLevel());
    gold = htons(info.getGoldAmount()); 
    safeGold = htons(info.getSafeGold());
    conversorTo8(life, 16);
    conversorTo8(maxLife, 16);
    conversorTo8(mana, 16);
    conversorTo8(maxMana, 16);
    conversorTo8(exp, 32);
    conversorTo8(maxExp, 32);
    conversorTo8(level, 16);
    conversorTo8(gold, 16);
    conversorTo8(safeGold, 16);
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
    uint16_t state = htons((uint16_t) info.getState());
    uint16_t dir = htons((uint16_t) info.getDirection());
    uint16_t posX = htons(info.getPoint().x);
    uint16_t posY = htons(info.getPoint().y);
    conversorTo8(state, 16);
    conversorTo8(dir, 16);
    conversorTo8(posX, 16);
    conversorTo8(posY, 16);
}

std::vector<uint8_t> CommunicationProtocol::encodePlayerInfo(const PlayerInfo info) {
    this->encodeMsg.clear();
    uint32_t length = PLAYERINFOLENGTH;
    length = htonl(length);
    conversorTo8(length, 32);
    uint8_t type = PLAYERINFOMSG;
    this->encodeMsg.push_back(type);
    uint16_t id = info.getId();
    id = htons(id);
    conversorTo8(id, 16);
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
    uint16_t id = ntohs(conversorTo16(msg.data()));
    uint16_t life = ntohs(conversorTo16(msg.data()+2));
    uint16_t maxLife = ntohs(conversorTo16(msg.data()+4));
    uint16_t mana = ntohs(conversorTo16(msg.data()+6));
    uint16_t maxMana = ntohs(conversorTo16(msg.data()+8));
    uint32_t exp = ntohl(conversorTo32(msg.data()+10));
    uint32_t maxExp = ntohl(conversorTo32(msg.data()+14));
    uint16_t level = ntohs(conversorTo16(msg.data()+18));
    uint16_t gold = ntohs(conversorTo16(msg.data()+20));
    uint16_t safeGold = ntohs(conversorTo16(msg.data()+22));
    std::string equipment = decodeEquipment(msg.data()+24,false);
    std::string inventory = decodeInventory(msg.data()+29);
    CharacterStateID state = (CharacterStateID) (ntohs(conversorTo16(msg.data()+38))); 
    Direction dir = (Direction) (ntohs(conversorTo16(msg.data()+40))); 
    uint16_t x = ntohs(conversorTo16(msg.data()+42)); 
    uint16_t y = ntohs(conversorTo16(msg.data()+44)); 
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
    for (int i=0; i<4;i++){
        this->encodeMsg.push_back(ZERO);
    }

    uint16_t posX = htons(object.getPoint().x);
    uint16_t posY = htons(object.getPoint().y);
    conversorTo8(posX,16);
    conversorTo8(posY,16);    
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
    conversorTo8(length, 32);
    this->encodeMsg.push_back(type);
    conversorTo8(cantObjects, 32);
    uint16_t id;
    for(auto& object: objects) {
        id = htons(object.getId());
        conversorTo8(id,16);
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
        uint16_t id = ntohs(conversorTo16(msg.data()+4+pos));
        uint8_t type = *(msg.data()+6+pos);
        equipment = decodeEquipment(msg.data()+7+pos,true);
        CharacterStateID state = (CharacterStateID) (ntohs(conversorTo16(msg.data()+13+pos))); 
        Direction dir = (Direction) (ntohs(conversorTo16(msg.data()+15+pos)));
        uint16_t x = ntohs(conversorTo16(msg.data()+17+pos)); 
        uint16_t y = ntohs(conversorTo16(msg.data()+19+pos));
        GameObjectInfo info(id,Point(x,y),equipment,dir,state,type);
        objects.push_back(info);
    }
    return std::move(objects);
}

std::vector<uint8_t> CommunicationProtocol::encodeCommand(InputInfo input) {
    this->encodeMsg.clear();
    uint32_t length = COMMANDLENGTH;
    length = htonl(length);
    conversorTo8(length,32);
    uint8_t type = COMMANDMSG;
    this->encodeMsg.push_back(type);
    uint8_t inputId = (uint8_t) input.input;
    this->encodeMsg.push_back(inputId);
    
    uint16_t x = htons(input.position.x);
    conversorTo8(x,16);
    uint16_t y = htons(input.position.y);
    conversorTo8(y,16);
    uint16_t adition = htons(input.aditional);
    conversorTo8(adition,16);

    return std::move(this->encodeMsg);
    
}

InputInfo CommunicationProtocol::decodeCommand(std::vector<uint8_t> msg) {
    InputInfo input;
    input.input = (InputID) *(msg.data());
    input.position.x = conversorTo16(msg.data()+1);
    input.position.y = conversorTo16(msg.data()+3);
    input.aditional = conversorTo16(msg.data()+5);
    return input;
 }

std::vector<uint8_t> CommunicationProtocol::encodeInit(RaceID race, GameClassID gameClass) {
    this->encodeMsg.clear();
    uint32_t lenght = INITLENGTH;
    conversorTo8(htonl(lenght),32);
    this->encodeMsg.push_back(INITMSG);
    uint8_t breed = (uint8_t) race;
    uint8_t playerClass = (uint8_t) gameClass;
    this->encodeMsg.push_back(breed);
    this->encodeMsg.push_back(playerClass);
    return std::move(this->encodeMsg);
}

CommunicationProtocol::~CommunicationProtocol() {}