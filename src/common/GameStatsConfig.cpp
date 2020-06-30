#include "GameStatsConfig.h"

GameStatsConfig::GameStatsConfig() {

}

float GameStatsConfig::getMaxHealth(RaceID, GameClassID, uint level) {
    return 0;
}

float GameStatsConfig::getRecoveryHealth(RaceID, GameClassID) {
    return 0;
}

float GameStatsConfig::getMaxMana(RaceID, GameClassID, uint exp) {
    return 0;
}

float GameStatsConfig::getRecoveryMana(RaceID, GameClassID) {
    return 0;
}

float GameStatsConfig::getRecoveryManaMeditation(RaceID, GameClassID) {
    return 0;
}

float GameStatsConfig::getGoldDrop(uint maxHealthNPC) {
    return 0;
}

float GameStatsConfig::getMaxGold(uint level) {
    return 0;
}

float GameStatsConfig::getNextLevelLimit(uint level) {
    return 0;
}

float GameStatsConfig::getExp(RaceID, GameClassID, uint level, uint enemyLevel) {
    return 0;
}

float GameStatsConfig::getAdditionalExp(RaceID, GameClassID, uint level, uint enemyLevel) {
    return 0;
}

float GameStatsConfig::getDamage(RaceID, GameClassID) {
    return 0;
}

bool GameStatsConfig::canEvade(RaceID) {
    return false;
}

float GameStatsConfig::getDefense() {
    return 0;
}

float GameStatsConfig::getTimeInSeconds(RaceID raceId, uint distance) {
    RaceInfo raceInfo = races.at(raceId);
    return 2 * (1 - raceInfo.agility/maxAgility) + 1;
}

void GameStatsConfig::setGoldRandMin(float goldRandMin) {
    GameStatsConfig::goldRandMin = goldRandMin;
}

void GameStatsConfig::setGoldRandMax(float goldRandMax) {
    GameStatsConfig::goldRandMax = goldRandMax;
}

void GameStatsConfig::setGoldMaxMult(float goldMaxMult) {
    GameStatsConfig::goldMaxMult = goldMaxMult;
}

void GameStatsConfig::setGoldMaxPot(float goldMaxPot) {
    GameStatsConfig::goldMaxPot = goldMaxPot;
}

void GameStatsConfig::setExpMaxMult(float expMaxMult) {
    GameStatsConfig::expMaxMult = expMaxMult;
}

void GameStatsConfig::setExpMaxPot(float expMaxPot) {
    GameStatsConfig::expMaxPot = expMaxPot;
}

void GameStatsConfig::setEvadeRandMin(float evadeRandMin) {
    GameStatsConfig::evadeRandMin = evadeRandMin;
}

void GameStatsConfig::setEvadeRandMax(float evadeRandMax) {
    GameStatsConfig::evadeRandMax = evadeRandMax;
}

void GameStatsConfig::setEvadeProbability(float evadeProbability) {
    GameStatsConfig::evadeProbability = evadeProbability;
}

void GameStatsConfig::setExpRandMin(float expRandMin) {
    GameStatsConfig::expRandMin = expRandMin;
}

void GameStatsConfig::setExpRandMax(float expRandMax) {
    GameStatsConfig::expRandMax = expRandMax;
}

void GameStatsConfig::setLevelDifference(float levelDifference) {
    GameStatsConfig::levelDifference = levelDifference;
}

void GameStatsConfig::setMaxAgility(float maxAgility) {
    GameStatsConfig::maxAgility = maxAgility;
}

void GameStatsConfig::insertRace(RaceID id, RaceInfo info) {
    races.insert(std::pair<RaceID, RaceInfo>(id, info));
}

void GameStatsConfig::insertGameClass(GameClassID id, GameClassInfo info) {
    gameClasses.insert(std::pair<GameClassID, GameClassInfo>(id, info));
}


GameStatsConfig::~GameStatsConfig() = default;
