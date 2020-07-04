#include "GameStatsConfig.h"

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

    rapidjson::Value::Array racesArray = json["races"].GetArray();
    for (auto &aRace : racesArray) {
        races.insert(std::pair<RaceID, RaceInfo>(RaceID(aRace["id"].GetInt()), createRaceInfo(aRace)));
    }
    rapidjson::Value::Array gameClassesArray = json["classes"].GetArray();
    for (auto &aGameClass : gameClassesArray) {
        gameClasses.insert(std::pair<GameClassID, GameClassInfo>(GameClassID(aGameClass["id"].GetInt()), createGameClass(aGameClass)));
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

float GameStatsConfig::getMaxHealth(RaceID, GameClassID, uint level) const {
    return 0;
}

float GameStatsConfig::getRecoveryHealth(RaceID, GameClassID) const {
    return 0;
}

float GameStatsConfig::getMaxMana(RaceID, GameClassID, uint exp) const {
    return 0;
}

float GameStatsConfig::getRecoveryMana(RaceID, GameClassID) const {
    return 0;
}

float GameStatsConfig::getRecoveryManaMeditation(RaceID, GameClassID) const {
    return 0;
}

float GameStatsConfig::getGoldDrop(uint maxHealthNPC) const{
    return 0;
}

float GameStatsConfig::getMaxGold(uint level) const{
    return 0;
}

float GameStatsConfig::getNextLevelLimit(uint level) const{
    return 0;
}

float GameStatsConfig::getExp(RaceID, GameClassID, uint level, uint enemyLevel) const {
    return 0;
}

float GameStatsConfig::getAdditionalExp(RaceID, GameClassID, uint level, uint enemyLevel) const{
    return 0;
}

float GameStatsConfig::getDamage(RaceID, GameClassID) const{
    return 0;
}

bool GameStatsConfig::canEvade(RaceID) const{
    return false;
}

float GameStatsConfig::getDefense() const{
    return 0;
}

uint8_t GameStatsConfig::getAmountMovements(RaceID raceId) const {
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

GameStatsConfig::GameStatsConfig() = default;

GameStatsConfig::~GameStatsConfig() = default;
