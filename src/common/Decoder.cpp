#include <netinet/in.h>
#include "Decoder.h"

#define ZERO 0x00
#define MAPMSG 0x00
#define PLAYERINFOMSG 0x01
#define OBJECTSINFOMSG 0x02
#define COMMANDMSG 0x03
#define INITMSG 0x04
#define INTERACTMSG 0x05
#define INITLENGTH 2
#define OBJECTLENGTH 18
#define PLAYERINFOLENGTH 47
#define COMMANDLENGTH 7
#define MAPLENGTH 240046
#define ITEM 0x01
#define CHARACTER 0x00


Decoder::Decoder() = default;

void Decoder::conversorTo8(uint32_t value, uint8_t from, std::vector<uint8_t>& encodeMsg) {
    int max;
    if (from == 16) {
        max = 2;
    } else if (from == 32) {
        max = 4;
    }
    auto* ptr = (uint8_t*) &value;
    for(int i = 0; i < max; i++)
        encodeMsg.push_back(*(ptr+i));
}

void Decoder::encodeStatsPlayer(const PlayerInfo &info, std::vector<uint8_t>& encodeMsg) {
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
    conversorTo8(life, 16, encodeMsg);
    conversorTo8(maxLife, 16, encodeMsg);
    conversorTo8(mana, 16, encodeMsg);
    conversorTo8(maxMana, 16, encodeMsg);
    conversorTo8(exp, 32, encodeMsg);
    conversorTo8(maxExp, 32, encodeMsg);
    conversorTo8(level, 16, encodeMsg);
    conversorTo8(gold, 16, encodeMsg);
    conversorTo8(safeGold, 16, encodeMsg);
}

void Decoder::encodeInventory(const PlayerInfo &info, std::vector<uint8_t>& encodeMsg) {
    std::string inventory = info.getInventory();
    std::string item;
    uint8_t idItem;
    for (int i = 0; i<9; i++) {
        item = inventory.substr(2*i+i,2);
        idItem = std::stoi(item);
        encodeMsg.push_back(idItem);
    }
}

void Decoder::encodeEquipmentPlayer(const PlayerInfo &info, std::vector<uint8_t>& encodeMsg) {
    uint8_t idHelmet = (uint8_t) info.getHelmetID();
    uint8_t idHead = (uint8_t) info.getHeadID();
    uint8_t idBody = (uint8_t) info.getBodyID();
    uint8_t idShield = (uint8_t) info.getShieldID();
    uint8_t idWeapon = (uint8_t) info.getWeaponID();

    encodeMsg.push_back(idHelmet);
    encodeMsg.push_back(idHead);
    encodeMsg.push_back(idBody);
    encodeMsg.push_back(idShield);
    encodeMsg.push_back(idWeapon);
}

void Decoder::encodeStatePlayer(const GameObjectInfo &info, std::vector<uint8_t>& encodeMsg) {
    uint16_t state = htons((uint16_t) info.getState());
    uint16_t dir = htons((uint16_t) info.getDirection());
    uint16_t posX = htons(info.getPoint().x);
    uint16_t posY = htons(info.getPoint().y);
    conversorTo8(state, 16, encodeMsg);
    conversorTo8(dir, 16, encodeMsg);
    conversorTo8(posX, 16, encodeMsg);
    conversorTo8(posY, 16, encodeMsg);
}

std::vector<uint8_t> Decoder::encodePlayerInfo(const PlayerInfo &info) {
    std::vector<uint8_t> encodeMsg;
    uint32_t length = PLAYERINFOLENGTH;
    length = htonl(length);
    conversorTo8(length, 32, encodeMsg);
    uint8_t type = PLAYERINFOMSG;
    encodeMsg.push_back(type);
    uint16_t id = info.getId();
    id = htons(id);
    conversorTo8(id, 16, encodeMsg);
    encodeStatsPlayer(info, encodeMsg);
    encodeEquipmentPlayer(info, encodeMsg);
    encodeInventory(info, encodeMsg);
    encodeStatePlayer(info, encodeMsg);
    uint8_t attackBy = (uint8_t) info.getAttackWeapon();
    encodeMsg.push_back(attackBy);
    return std::move(encodeMsg);
}

std::string Decoder::decodeEquipment(Message& msg, bool isGameObject) {
    std::string equipment;
    uint8_t id;
    std::string temp;
    equipment += "ht";
    id = msg.read8();
    temp = std::to_string(id);
    if (temp.size() == 1)
        equipment += "0";
    equipment += temp + "|";
    equipment += "h";
    id = msg.read8();
    temp = std::to_string(id);
    if (temp.size() == 1)
        equipment += "0";
    equipment += temp + "|";
    equipment += "b";
    id = msg.read8();
    temp = std::to_string(id);
    if (temp.size() == 1)
        equipment += "0";
    equipment += temp + "|";
    equipment += "s";
    id = msg.read8();
    temp = std::to_string(id);
    if (temp.size() == 1)
        equipment += "0";
    equipment += temp + "|";
    equipment += "w";
    id = msg.read8();
    temp = std::to_string(id);
    if (temp.size() == 1)
        equipment += "0";
    equipment += temp;
    if(isGameObject) {
        equipment +="|i";
        id = msg.read8();
        temp = std::to_string(id);
        if (temp.size() == 1)
            equipment += "0";
        equipment += temp;
    }
    return std::move(equipment);
}

std::string Decoder::decodeInventory(Message& msg) {
    std::string inventory;
    uint8_t id;
    std::string temp;
    for (int i=0; i<9;i++) {
        id = msg.read8();
        temp = std::to_string(id);
        if (temp.size() == 1)
            inventory += "0";
        inventory += temp;
        if (i != 8)
            inventory += "|";
    }
    return std::move(inventory);
}

PlayerInfo Decoder::decodePlayerInfo(Message msg) {
    msg.clear();
    uint16_t id = ntohs(msg.read16());
    uint16_t life = ntohs(msg.read16());
    uint16_t maxLife = ntohs(msg.read16());
    uint16_t mana = ntohs(msg.read16());
    uint16_t maxMana = ntohs(msg.read16());
    uint32_t exp = ntohl(msg.read32());
    uint32_t maxExp = ntohl(msg.read32());
    uint16_t level = ntohs(msg.read16());
    uint16_t gold = ntohs(msg.read16());
    uint16_t safeGold = ntohs(msg.read16());
    std::string equipment = decodeEquipment(msg, false);
    std::string inventory = decodeInventory(msg);
    auto state = (CharacterStateID) (ntohs(msg.read16()));
    auto dir = (Direction) (ntohs(msg.read16()));
    uint16_t x = ntohs(msg.read16());
    uint16_t y = ntohs(msg.read16());
    auto attackBy = (WeaponID) msg.read8();
    PlayerInfo info(id, Point(x,y), gold, life, mana, equipment, dir,
                    safeGold,maxLife,maxMana,exp,maxExp,level,inventory,state,attackBy);
    return info;
}

void Decoder::encodeItem(GameObjectInfo object, std::vector<uint8_t>& encodeMsg) {
    encodeMsg.push_back(ITEM);
    auto idHelmet = (uint8_t) object.getHelmetID();
    auto idHead = (uint8_t) object.getHeadID();
    auto idBody = (uint8_t) object.getBodyID();
    auto idShield = (uint8_t) object.getShieldID();
    auto idWeapon = (uint8_t) object.getWeaponID();
    auto idItem = (uint8_t) object.getItemID();

    encodeMsg.push_back(idHelmet);
    encodeMsg.push_back(idHead);
    encodeMsg.push_back(idBody);
    encodeMsg.push_back(idShield);
    encodeMsg.push_back(idWeapon);
    encodeMsg.push_back(idItem);
    //Encodeo el estado y direccion del item con 0 dado que no me interesa su valor
    for (int i=0; i<4;i++){
        encodeMsg.push_back(ZERO);
    }

    uint16_t posX = htons(object.getPoint().x);
    uint16_t posY = htons(object.getPoint().y);
    conversorTo8(posX,16, encodeMsg);
    conversorTo8(posY,16, encodeMsg);
    encodeMsg.push_back(ZERO); //Un item no puede ser atacado
}

void Decoder::encodeCharacter(GameObjectInfo object, std::vector<uint8_t>& encodeMsg) {
    encodeMsg.push_back(CHARACTER);
    auto idHelmet = (uint8_t) object.getHelmetID();
    auto idHead = (uint8_t) object.getHeadID();
    auto idBody = (uint8_t) object.getBodyID();
    auto idShield = (uint8_t) object.getShieldID();
    auto idWeapon = (uint8_t) object.getWeaponID();
    auto attackBy = (uint8_t) object.getAttackWeapon();
    encodeMsg.push_back(idHelmet);
    encodeMsg.push_back(idHead);
    encodeMsg.push_back(idBody);
    encodeMsg.push_back(idShield);
    encodeMsg.push_back(idWeapon);
    encodeMsg.push_back(ZERO); //Correspondiente al valor del item que no es
    encodeStatePlayer(object, encodeMsg);
    encodeMsg.push_back(attackBy);
}

std::vector<uint8_t> Decoder::encodeGameObjects(const std::vector<GameObjectInfo> &objects) {
    std::vector<uint8_t> encodeMsg;
    uint32_t cantObjects = objects.size();
    uint32_t length = cantObjects * OBJECTLENGTH + 4;
    length = htonl(length);
    cantObjects = htonl(cantObjects);
    uint8_t type = OBJECTSINFOMSG;
    conversorTo8(length, 32, encodeMsg);
    encodeMsg.push_back(type);
    conversorTo8(cantObjects, 32, encodeMsg);
    uint16_t id;
    for(auto& object: objects) {
        id = htons(object.getId());
        conversorTo8(id,16, encodeMsg);
        if(object.isItem()) {
            encodeItem(object, encodeMsg);
        } else {
            encodeCharacter(object, encodeMsg);
        }
    }
    return std::move(encodeMsg);
}

std::vector<GameObjectInfo> Decoder::decodeGameObjects(Message msg) {
    std::vector<GameObjectInfo> objects;
    msg.clear();
    uint32_t cantObjects = ntohl(msg.read32());
    uint32_t pos;
    std::string equipment;
    for (int i=0; i < cantObjects ; i++) {
        uint16_t id = ntohs(msg.read16());
        uint8_t type = msg.read8();
        equipment = decodeEquipment(msg, true);
        auto state = (CharacterStateID) (ntohs(msg.read16()));
        auto dir = (Direction) (ntohs(msg.read16()));
        uint16_t x = ntohs(msg.read16());
        uint16_t y = ntohs(msg.read16());
        auto attackBy = (WeaponID) msg.read8();
        GameObjectInfo info(id,Point(x,y),equipment,dir,state,type,attackBy);
        objects.push_back(info);
    }
    return std::move(objects);
}

std::vector<uint8_t> Decoder::encodeCommand(InputInfo input) {
    std::vector<uint8_t> encodeMsg;
    uint32_t length = COMMANDLENGTH;
    length = htonl(length);
    conversorTo8(length,32, encodeMsg);
    uint8_t type = COMMANDMSG;
    encodeMsg.push_back(type);
    auto inputId = (uint8_t) input.input;
    encodeMsg.push_back(inputId);

    uint16_t x = htons(input.position.x);
    conversorTo8(x,16, encodeMsg);
    uint16_t y = htons(input.position.y);
    conversorTo8(y,16, encodeMsg);
    uint16_t adition = htons(input.aditional);
    conversorTo8(adition,16, encodeMsg);

    return std::move(encodeMsg);

}

InputInfo Decoder::decodeCommand(Message msg) {
    msg.clear();
    InputInfo input;
    input.input = (InputID) msg.read8();
    input.position.x = ntohs(msg.read16());
    input.position.y = ntohs(msg.read16());
    input.aditional = ntohs(msg.read16());
    return input;
}

std::vector<uint8_t> Decoder::encodeInit(RaceID race, GameClassID gameClass) {
    std::vector<uint8_t> encodeMsg;
    uint32_t length = INITLENGTH;
    conversorTo8(htonl(length),32, encodeMsg);
    encodeMsg.push_back(INITMSG);
    auto breed = (uint8_t) race;
    auto playerClass = (uint8_t) gameClass;
    encodeMsg.push_back(breed);
    encodeMsg.push_back(playerClass);
    return std::move(encodeMsg);
}

std::vector<uint8_t> Decoder::encodeMap(const TiledMap &tiledMap) {
    std::vector<uint8_t> encodeMsg;
    uint32_t length = MAPLENGTH;
    conversorTo8(htonl(length), 32, encodeMsg);
    encodeMsg.push_back(MAPMSG);
    conversorTo8(htons(tiledMap.getWidth()), 16, encodeMsg);
    conversorTo8(htons(tiledMap.getHeight()), 16, encodeMsg);
    encodeMsg.push_back(tiledMap.getTileWidth());
    encodeMsg.push_back(tiledMap.getTileHeight());
    std::vector<TileLayer> tilesLayers = tiledMap.getTileLayers();
    uint8_t amountLayers = tilesLayers.size();
    uint16_t dataSize = tilesLayers.at(0).getData().size();
    encodeMsg.push_back(amountLayers);
    conversorTo8(htons(dataSize), 16, encodeMsg);
    for (auto &aTileLayer : tilesLayers) {
        encodeMsg.push_back(aTileLayer.isGroundLayer() ? 0X01 : ZERO);
        for (auto &aDataTile : aTileLayer.getData()) {
            conversorTo8(htons(aDataTile), 16, encodeMsg);
        }
    }
    std::vector<TileSet> tilesSet = tiledMap.getTilesets();
    uint8_t amountTileSets = tilesSet.size();
    encodeMsg.push_back(amountTileSets);
    for (auto &aTileSet : tilesSet) {
        conversorTo8(htons(aTileSet.getFirstgid()), 16, encodeMsg);
        encodeMsg.push_back(aTileSet.getId());
    }
    return std::move(encodeMsg);
}

TiledMap Decoder::decodeMap(Message msg) {
    uint16_t width = ntohs(msg.read16());
    uint16_t height = ntohs(msg.read16());
    uint8_t tileWidth = msg.read8();
    uint8_t tileHeight = msg.read8();
    uint8_t amountLayers = msg.read8();
    uint16_t dataSize = ntohs(msg.read16());
    std::vector<TileLayer> tileLayers;
    for (size_t i = 0; i < amountLayers; ++i) {
        std::vector<uint16_t> data;
        bool isGround = msg.read8();
        for (size_t j = 0; j < dataSize; ++j) {
            data.push_back(ntohs(msg.read16()));
        }
        tileLayers.emplace_back(data, isGround);
    }
    std::vector<TileSet> tileSets;
    uint8_t amountTileSets = msg.read8();
    for (size_t i = 0; i < amountTileSets; ++i) {
        uint16_t firstGid = ntohs(msg.read16());
        uint8_t id = msg.read8();
        tileSets.emplace_back(firstGid, id);
    }
    return TiledMap(width, height, tileWidth, tileHeight, tileLayers, tileSets);
}

std::vector<uint8_t> Decoder::encodeNPCInfo(NPCInfo info) {
    std::vector<uint8_t> encodeMsg;
    uint32_t length = 0;
    conversorTo8(htonl(length), 32, encodeMsg);
    encodeMsg.push_back(INTERACTMSG);
    length += 1;
    encodeMsg.push_back(info.type);
    uint8_t cantAccions = info.actions.size();
    length += 1;
    encodeMsg.push_back(cantAccions);
    for (auto iter: info.actions) {
        length += 1;
        encodeMsg.push_back(uint8_t(iter));
    }
    if (info.type != 0) {
        uint8_t cantItems = info.items.size();
        length += 1;
        encodeMsg.push_back(cantItems);
        for (auto iter: info.items) {
            length += 3;
            encodeMsg.push_back(uint8_t(iter.first));
            conversorTo8(htons(iter.second), 16, encodeMsg);
        }
    } else {
        uint8_t cantItems = ZERO;
        length += 1;
        encodeMsg.push_back(cantItems);
    }
    uint32_t gold = info.gold;
    length += 4;
    conversorTo8(htonl(gold),32,encodeMsg);
    if (info.type == 3) {
        uint8_t cantItems = info.itemsInBank.size();
        length += 1;
        encodeMsg.push_back(cantItems);
        for (auto iter: info.itemsInBank) {
            length += 1;
            encodeMsg.push_back(uint8_t(iter));
        }
    } else {
        uint8_t cantItems = ZERO;
        length += 1;
        encodeMsg.push_back(cantItems);
    }
    length = htonl(length);
    auto* ptr = (uint8_t*) &length;
    for(int i = 0; i < 4; i++)
        encodeMsg.at(i) = *(ptr+i);

    return std::move(encodeMsg);
}

NPCInfo Decoder::decodeNPCInfo(Message msg){
    NPCInfo info;
    info.type = msg.read8();
    uint8_t cantAccions = msg.read8();
    for (uint8_t i=0; i < cantAccions; i++) {
        info.actions.push_back(ActionsProfessionID(msg.read8()));
    }
    uint8_t cantItems = msg.read8();
    for (uint8_t i=0; i < cantItems; i++) {
        ItemsInventoryID id = ItemsInventoryID(msg.read8());
        uint16_t cost = ntohs(msg.read16());
        info.items.insert({id,cost});
    }
    info.gold = ntohl(msg.read32());
    uint8_t cantItemsInBank = msg.read8();
    for (uint8_t i=0; i < cantItemsInBank; i++) {
        info.itemsInBank.push_back(ItemsInventoryID(msg.read8()));
    }
    return info;
}

Decoder::~Decoder() = default;
