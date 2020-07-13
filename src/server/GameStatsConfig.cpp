#include "GameStatsConfig.h"
#include "../common/Random.h"
#include "ItemTranslator.h"
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
    inventoryLimit = json["inventoryLimit"].GetInt();

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

    rapidjson::Value::Array creatuesArray = json["creatures"].GetArray();
    for (auto &aCreature : racesArray) {
        creatures.insert(std::pair<CreatureID, CreatureInfo>(CreatureID(aCreature["id"].GetInt()), createCreatureInfo(aCreature)));
    }
}

RaceInfo GameStatsConfig::createRaceInfo(rapidjson::Value &value) {
    RaceInfo aRaceInfo{};
    aRaceInfo.intelligent = value["intelligent"].GetFloat();
    aRaceInfo.recoveryTime = value["recoveryTime"].GetFloat();
    aRaceInfo.constitution = value["constitution"].GetFloat();
    aRaceInfo.strength = value["strength"].GetFloat();
    aRaceInfo.agility = value["agility"].GetFloat();
    aRaceInfo.health = value["health"].GetFloat();
    aRaceInfo.mana = value["mana"].GetFloat();
    return aRaceInfo;
}

GameClassInfo GameStatsConfig::createGameClass(rapidjson::Value &value) {
    GameClassInfo aGameClassInfo{};
    aGameClassInfo.health = value["health"].GetFloat();
    aGameClassInfo.mana = value["mana"].GetFloat();
    aGameClassInfo.meditation = value["meditation"].GetFloat();
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
    aItemInfo.range = value["range"].GetInt();
    return aItemInfo;
}

CreatureInfo GameStatsConfig::createCreatureInfo(rapidjson::Value& value) {
    CreatureInfo aCreatureInfo{};
    aCreatureInfo.strength = value["strength"].GetFloat();
    aCreatureInfo.agility = value["agility"].GetFloat();
    aCreatureInfo.health = value["health"].GetFloat();
    return aCreatureInfo;
}

const ItemInfo GameStatsConfig::getItem(ItemsInventoryID id) {
    return items.at(id);
}

float GameStatsConfig::getMaxHealth(RaceID raceId, GameClassID gameClass, uint level) {
    float max = races.at(raceId).constitution * gameClasses.at(gameClass).health * races.at(raceId).health * level;
    return max;
}

float GameStatsConfig::getRecoveryHealth(RaceID raceId) {
    return races.at(raceId).recoveryTime;
}

float GameStatsConfig::getMaxMana(RaceID raceId, GameClassID gameClass, uint level) {
    float max = races.at(raceId).intelligent * races.at(raceId).mana * gameClasses.at(gameClass).mana * level;
    return max;
}

float GameStatsConfig::getRecoveryMana(RaceID race) {
    return races.at(race).recoveryTime;
}

float GameStatsConfig::getRecoveryManaMeditation(RaceID race, GameClassID gameClass) {
    return (races.at(race).intelligent * gameClasses.at(gameClass).meditation);
}

float GameStatsConfig::getGoldDrop(CreatureID creatureId, uint level){
    return Random::getFloat(goldRandMin, goldRandMax) * GameStatsConfig::getMaxHealth(creatureId, level);
}

float GameStatsConfig::getMaxGold(uint level){
    return goldMaxMult * pow(level, goldMaxPot);
}

float GameStatsConfig::getNextLevelLimit(uint level){
    return expMaxMult * pow(level, expMaxPot);
}

float GameStatsConfig::getExp(float damage, uint level, uint enemyLevel) {
    return damage * std::max((int)(enemyLevel - level + levelDifference), 0);
}

float GameStatsConfig::getAdditionalExp(float damage, float enemyMaxLife , uint level, uint enemyLevel){
    return Random::getFloat(expRandMin, expRandMax) * enemyMaxLife * std::max((int)(enemyLevel - level + levelDifference), 0);
}

float GameStatsConfig::getDamage(RaceID raceId, WeaponID weaponId){
    RaceInfo aRaceInfo = races.at(raceId);
    if (weaponId == WeaponID::Nothing) {
        return aRaceInfo.strength;
    }
    ItemInfo aWeapon = items.at(ItemTranslator::weaponToItem(weaponId));
    return aRaceInfo.strength * Random::get(aWeapon.minDamage, aWeapon.maxDamage);
}

bool GameStatsConfig::canEvade(RaceID race){
    double base = Random::getFloat(evadeRandMin,evadeRandMax);
    return pow(base, races.at(race).agility) < evadeProbability;
}

uint8_t GameStatsConfig::getAmountSteps(RaceID raceId) {
    RaceInfo raceInfo = races.at(raceId);
    return  5 + (maxAgility - raceInfo.agility);
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

std::map<ItemsInventoryID,ItemInfo> GameStatsConfig::getItems() {
    return items;
}

float GameStatsConfig::getDistance(){
    return distance;
}

uint8_t GameStatsConfig::getAmountSteps(CreatureID creatureId) {
    return 10 + (maxAgility - creatures.at(creatureId).agility);
}

float GameStatsConfig::getDamage(CreatureID creatureId){
    return creatures.at(creatureId).strength;
}

float GameStatsConfig::getDefense(BodyID bodyId, ShieldID shieldId, HelmetID helmetId) {
    float defense = 0.0;
    ItemInfo aItemInfo;
    if (bodyId != BodyID::Nothing) {
        aItemInfo = items.at(ItemTranslator::bodyToItem(bodyId));
        defense += Random::get(aItemInfo.minDefense, aItemInfo.maxDefense);
    }
    if (shieldId != ShieldID::Nothing) {
        aItemInfo = items.at(ItemTranslator::shieldToItem(shieldId));
        defense += Random::get(aItemInfo.minDefense, aItemInfo.maxDefense);
    }
    if (helmetId != HelmetID::Nothing) {
        aItemInfo = items.at(ItemTranslator::helmetToItem(helmetId));
        defense += Random::get(aItemInfo.minDefense, aItemInfo.maxDefense);
    }
    return defense;
}

float GameStatsConfig::getDefense(CreatureID creatureId) {
    return 0;
}

bool GameStatsConfig::canEvade(CreatureID creatureId) {
    double base = Random::getFloat(evadeRandMin,evadeRandMax);
    return pow(base, creatures.at(creatureId).agility) < evadeProbability;
}

float GameStatsConfig::getMaxHealth(CreatureID creatureId, uint level) {
    return creatures.at(creatureId).health * level;
}

int GameStatsConfig::getInventoryLimit() {
    return GameStatsConfig::inventoryLimit;
}

int GameStatsConfig::getWeaponDistance(WeaponID aWeaponId) {
    if ( aWeaponId == WeaponID::Nothing) {
        return 1;
    }
    ItemInfo aItemInfo = items.at(ItemTranslator::weaponToItem(aWeaponId));
    return aItemInfo.range;
}

int GameStatsConfig::getWeaponCost(WeaponID aWeaponId) {
    return items.at(ItemTranslator::weaponToItem(aWeaponId)).manaUsed;
}

GameStatsConfig::GameStatsConfig() = default;

GameStatsConfig::~GameStatsConfig() = default;

std::unordered_map<RaceID, RaceInfo, std::hash<RaceID>> GameStatsConfig::races;
std::unordered_map<GameClassID, GameClassInfo, std::hash<GameClassID>> GameStatsConfig::gameClasses;
std::map<ItemsInventoryID, ItemInfo> GameStatsConfig::items;
std::unordered_map<CreatureID, CreatureInfo, std::hash<CreatureID>> GameStatsConfig::creatures;
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
uint8_t GameStatsConfig::levelDifference = 0;
float GameStatsConfig::maxAgility = 0.0;
uint8_t GameStatsConfig::creaturesLimit = 0.0;
uint8_t GameStatsConfig::nestCreaturesLimit = 0.0;
float GameStatsConfig::distance = 0.0;
int GameStatsConfig::inventoryLimit = 0;
