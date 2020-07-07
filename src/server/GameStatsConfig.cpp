#include "GameStatsConfig.h"
#include "../common/Random.h"

GameStatsConfig::GameStatsConfig(rapidjson::Document &json) {
    GameStatsConfig gameStatsConfig;
    port = json["port"].GetString();
    goldRandMin = json["goldRandMin"].GetFloat();
    goldRandMax = json["goldRandMax"].GetFloat();
    goldMaxMult = json["goldMaxMult"].GetFloat();
    goldMaxPot = json["goldMaxPot"].GetFloat();
    expRandMin = json["expRandMin"].GetFloat();
    expRandMax = json["expRandMax"].GetFloat();
    expMaxMult = json["expMaxMult"].GetFloat();
    expMaxPot = json["expMaxPot"].GetFloat();
    evadeRandMin = json["evadeRandMin"].GetFloat();
    evadeRandMax = json["evadeRandMax"].GetFloat();
    evadeProbability = json["evadeProbability"].GetFloat();
    levelDifference = json["levelDifference"].GetFloat();
    maxAgility = json["maxAgility"].GetFloat();
    creaturesLimit = json["creaturesLimit"].GetInt();
    nestCreaturesLimit = json["nestCreaturesLimit"].GetInt();
    distance = json["distance"].GetFloat();

    rapidjson::Value::Array racesArray = json["races"].GetArray();
    for (auto &aRace : racesArray) {
        races.insert(std::pair<RaceID, RaceInfo>(RaceID(aRace["id"].GetInt()), createRaceInfo(aRace)));
    }
    rapidjson::Value::Array gameClassesArray = json["classes"].GetArray();
    for (auto &aGameClass : gameClassesArray) {
        gameClasses.insert(std::pair<GameClassID, GameClassInfo>(GameClassID(aGameClass["id"].GetInt()), createGameClass(aGameClass)));
    }

    rapidjson::Value::Array itemsArray = json["items"].GetArray();
    for (auto &aItem: itemsArray) {
        items.insert(std::pair<ItemsInventoryID, ItemInfo>(ItemsInventoryID(aItem["id"].GetInt()), createItem(aItem)));
    }
}

RaceInfo GameStatsConfig::createRaceInfo(rapidjson::Value &value) {
    RaceInfo aRaceInfo{};
    aRaceInfo.intelligent = value["intelligent"].GetInt();
    aRaceInfo.recoveryTime = value["recoveryTime"].GetInt();
    aRaceInfo.constitution = value["constitution"].GetInt();
    aRaceInfo.strength = value["strength"].GetInt();
    aRaceInfo.agility = value["agility"].GetInt();
    aRaceInfo.health = value["health"].GetInt();
    aRaceInfo.mana = value["mana"].GetInt();
    return aRaceInfo;
}

GameClassInfo GameStatsConfig::createGameClass(rapidjson::Value &value) {
    GameClassInfo aGameClassInfo{};
    aGameClassInfo.health = value["health"].GetInt();
    aGameClassInfo.mana = value["mana"].GetInt();
    aGameClassInfo.meditation = value["meditation"].GetInt();
    return aGameClassInfo;
}

ItemInfo GameStatsConfig::createItem(rapidjson::Value& value) {
    ItemInfo aItemInfo{};
    aItemInfo.name = value["name"].GetString();
    aItemInfo.damage = value["damage"].GetBool();
    aItemInfo.minDamage = value["minDamage"].GetInt();
    aItemInfo.maxDamage = value["maxDamage"].GetInt();
    aItemInfo.manaUsed = value["manaUsed"].GetInt();
    aItemInfo.manaRestored = value["manaRestored"].GetInt();
    aItemInfo.healthRestored = value["healthRestored"].GetInt();
    aItemInfo.minDefense = value["minDefense"].GetInt();
    aItemInfo.maxDefense = value["maxDefense"].GetInt();
    aItemInfo.goldCost = value["goldCost"].GetInt();
    aItemInfo.type = value["type"].GetString();
    aItemInfo.hasRange = value["hasRange"].GetBool();
    return aItemInfo;
}

float GameStatsConfig::getMaxHealth(RaceID race, GameClassID gameClass, uint level) const {
    return races.at(race).constitution * gameClasses.at(gameClass).health * races.at(race).health * level;
}

float GameStatsConfig::getRecoveryHealth(RaceID race, GameClassID gameClass) const {
    return 0;
}

float GameStatsConfig::getMaxMana(RaceID race, GameClassID gameClass, uint level) const {
    return races.at(race).intelligent*races.at(race).mana*gameClasses.at(gameClass).mana*level;
}

float GameStatsConfig::getRecoveryMana(RaceID race, GameClassID gameClass) const {
    return 0;
}

float GameStatsConfig::getRecoveryManaMeditation(RaceID race, GameClassID gameClass) const {
    return races.at(race).intelligent * gameClasses.at(gameClass).meditation;
}

float GameStatsConfig::getGoldDrop(uint maxHealthNPC) const{
    return 100;
}

float GameStatsConfig::getMaxGold(uint level) const{
    return goldMaxMult * pow(level, goldMaxPot);
}

float GameStatsConfig::getNextLevelLimit(uint level) const{
    return expMaxMult * pow(level,expMaxPot);
}

float GameStatsConfig::getExp(RaceID race, GameClassID gameClass, uint level, uint enemyLevel) const {
    return 0;
}

float GameStatsConfig::getAdditionalExp(RaceID race, GameClassID gameClass, uint level, uint enemyLevel) const{
    return 0;
}

float GameStatsConfig::getDamage(RaceID race, WeaponID weaponId) const{
    return 0;
}

bool GameStatsConfig::canEvade(RaceID race) const{
    double base = Random::getFloat(evadeRandMin,evadeRandMax);
    return pow(base, races.at(race).agility) < evadeProbability;
}

uint8_t GameStatsConfig::getAmountSteps(RaceID raceId) const {
    RaceInfo raceInfo = races.at(raceId);
    return  3 + (maxAgility - raceInfo.agility);
}

uint8_t GameStatsConfig::getCreaturesLimit() const {
    return creaturesLimit;
}

uint8_t GameStatsConfig::getNestCreatureLimit() const {
    return nestCreaturesLimit;
}

std::string GameStatsConfig::getPort() const {
    return port;
}

std::unordered_map<ItemsInventoryID,ItemInfo> GameStatsConfig::getItems() const {
    return items;
}

float GameStatsConfig::getDistance() const{
    return distance;
}

uint8_t GameStatsConfig::getAmountSteps(CreatureID creatureId) const {
    return 20;
}

float GameStatsConfig::getDamage(CreatureID) const{
    return 5;
}

float GameStatsConfig::getDefense(BodyID bodyId, ShieldID shieldId, HelmetID helmetId) const {
    return 0;
}

GameStatsConfig::GameStatsConfig() = default;

GameStatsConfig::~GameStatsConfig() = default;
