#include "GameStatsConfig.h"
#include "../common/Random.h"
#include <iostream>

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

const ItemInfo GameStatsConfig::getItem(ItemsInventoryID id) {
    return items.at(id);
}

float GameStatsConfig::getMaxHealth(RaceID race, GameClassID gameClass, uint level) {
    float max = races.at(race).constitution * gameClasses.at(gameClass).health * races.at(race).health * level;
    std::cout << max << std::endl;
    return max;
}

float GameStatsConfig::getRecoveryHealth(RaceID race, GameClassID gameClass) {
    return 0;
}

float GameStatsConfig::getMaxMana(RaceID race, GameClassID gameClass, uint level) {
    float max = races.at(race).intelligent*races.at(race).mana*gameClasses.at(gameClass).mana*level;
    std::cout <<"mana: " << max << std::endl;
    return max;
}

float GameStatsConfig::getRecoveryMana(RaceID race, GameClassID gameClass) {
    return 0;
}

float GameStatsConfig::getRecoveryManaMeditation(RaceID race, GameClassID gameClass) {
    return races.at(race).intelligent * gameClasses.at(gameClass).meditation;
}

float GameStatsConfig::getGoldDrop(uint maxHealthNPC){
    return 100;
}

float GameStatsConfig::getMaxGold(uint level){
    return GameStatsConfig::goldMaxMult * pow(level, GameStatsConfig::goldMaxPot);
}

float GameStatsConfig::getNextLevelLimit(uint level){
    return expMaxMult * pow(level,expMaxPot);
}

float GameStatsConfig::getExp(RaceID race, GameClassID gameClass, uint level, uint enemyLevel) {
    return 0;
}

float GameStatsConfig::getAdditionalExp(RaceID race, GameClassID gameClass, uint level, uint enemyLevel){
    return 0;
}

float GameStatsConfig::getDamage(RaceID race, WeaponID weaponId){
    return 10;
}

bool GameStatsConfig::canEvade(RaceID race){
    double base = Random::getFloat(evadeRandMin,evadeRandMax);
    return pow(base, races.at(race).agility) < evadeProbability;
}

uint8_t GameStatsConfig::getAmountSteps(RaceID raceId) {
    RaceInfo raceInfo = races.at(raceId);
    return  3 + (maxAgility - raceInfo.agility);
}

uint8_t GameStatsConfig::getCreaturesLimit() {
    return creaturesLimit;
}

uint8_t GameStatsConfig::getNestCreatureLimit() {
    return nestCreaturesLimit;
}

std::string GameStatsConfig::getPort() {
    return port;
}

std::unordered_map<ItemsInventoryID,ItemInfo> GameStatsConfig::getItems() {
    return items;
}

float GameStatsConfig::getDistance(){
    return distance;
}

uint8_t GameStatsConfig::getAmountSteps(CreatureID creatureId) {
    return 20;
}

float GameStatsConfig::getDamage(CreatureID){
    return 5;
}

float GameStatsConfig::getDefense(BodyID bodyId, ShieldID shieldId, HelmetID helmetId) {
    return 0;
}

float GameStatsConfig::getDefense(CreatureID creatureId) {
    return 0;
}

GameStatsConfig::GameStatsConfig() = default;

GameStatsConfig::~GameStatsConfig() = default;

std::unordered_map<RaceID, RaceInfo, std::hash<RaceID>> GameStatsConfig::races;
std::unordered_map<GameClassID, GameClassInfo, std::hash<GameClassID>> GameStatsConfig::gameClasses;
std::unordered_map<ItemsInventoryID, ItemInfo, std::hash<ItemsInventoryID>> GameStatsConfig::items;
std::string GameStatsConfig::port{};
float GameStatsConfig::goldRandMin = 0.0;
float GameStatsConfig::goldRandMax = 0.0;
float GameStatsConfig::goldMaxMult = 0.0;
float GameStatsConfig::goldMaxPot = 0.0;
float GameStatsConfig::expMaxMult = 0.0;
float GameStatsConfig::expMaxPot = 0.0;
float GameStatsConfig::evadeRandMin = 0.0;
float GameStatsConfig::evadeRandMax = 0.0;
float GameStatsConfig::evadeProbability = 0.0;
float GameStatsConfig::expRandMin = 0.0;
float GameStatsConfig::expRandMax = 0.0;
float GameStatsConfig::levelDifference = 0.0;
float GameStatsConfig::maxAgility = 0.0;
uint8_t GameStatsConfig::creaturesLimit = 0.0;
uint8_t GameStatsConfig::nestCreaturesLimit = 0.0;
float GameStatsConfig::distance = 0.0;
