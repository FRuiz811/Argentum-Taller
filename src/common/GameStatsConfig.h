#ifndef ARGENTUM_TALLER_GAMESTATSCONFIG_H
#define ARGENTUM_TALLER_GAMESTATSCONFIG_H

#include <unordered_map>
#include "GameStats.h"
#include "Identificators.h"
#include <rapidjson/document.h>

class GameStatsConfig {
private:
    std::unordered_map<RaceID, RaceInfo, std::hash<RaceID>> races;
    std::unordered_map<GameClassID, GameClassInfo, std::hash<GameClassID>> gameClasses;
    float goldRandMin{};
    float goldRandMax{};
    float goldMaxMult{};
    float goldMaxPot{};
    float expMaxMult{};
    float expMaxPot{};
    float evadeRandMin{};
    float evadeRandMax{};
    float evadeProbability{};
    float expRandMin{};
    float expRandMax{};
    float levelDifference{};
    float maxAgility{};
    uint8_t creaturesLimit{};
    uint8_t nestCreaturesLimit{};
public:
    GameStatsConfig();

    explicit GameStatsConfig(rapidjson::Document &json);

    virtual ~GameStatsConfig();

    float getMaxHealth(RaceID, GameClassID, uint level) const;
    float getRecoveryHealth(RaceID, GameClassID) const;
    float getMaxMana(RaceID, GameClassID, uint exp) const;
    float getRecoveryMana(RaceID, GameClassID) const;
    float getRecoveryManaMeditation(RaceID, GameClassID) const;
    float getGoldDrop(uint maxHealthNPC) const;
    float getMaxGold(uint level) const;
    float getNextLevelLimit(uint level) const;
    float getExp(RaceID, GameClassID, uint level, uint enemyLevel) const;
    float getAdditionalExp(RaceID, GameClassID, uint level, uint enemyLevel) const;
    float getDamage(RaceID, GameClassID) const;
    bool canEvade(RaceID) const;
    float getDefense() const;
    uint8_t getAmountMovements(RaceID raceId) const;
    uint8_t getCreaturesLimit() const;
    RaceInfo createRaceInfo(rapidjson::Value &value);
    GameClassInfo createGameClass(rapidjson::Value &value);
    uint8_t getNestCreatureLimit() const ;
};


#endif //ARGENTUM_TALLER_GAMESTATSCONFIG_H
