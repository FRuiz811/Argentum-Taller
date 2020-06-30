#ifndef ARGENTUM_TALLER_GAMESTATSCONFIG_H
#define ARGENTUM_TALLER_GAMESTATSCONFIG_H

#include <unordered_map>
#include "GameStats.h"

class GameStatsConfig {
private:
    std::unordered_map<RaceID, RaceInfo, std::hash<RaceID>> races;
    std::unordered_map<GameClassID, GameClassInfo, std::hash<GameClassID>> gameClasses;
    float goldRandMin;
    float goldRandMax;
    float goldMaxMult;
    float goldMaxPot;
    float expMaxMult;
    float expMaxPot;
    float evadeRandMin;
    float evadeRandMax;
    float evadeProbability;
    float expRandMin;
    float expRandMax;
    float levelDifference;
    float maxAgility;
public:
    GameStatsConfig();

    virtual ~GameStatsConfig();

    void setGoldRandMin(float goldRandMin);

    void setGoldRandMax(float goldRandMax);

    void setGoldMaxMult(float golMaxMult);

    void setGoldMaxPot(float goldMaxPot);

    void setExpMaxMult(float expMaxMult);

    void setExpMaxPot(float expMaxPot);

    void setEvadeRandMin(float evadeRandMin);

    void setEvadeRandMax(float evadeRandMax);

    void setEvadeProbability(float evadeProbability);

    void setExpRandMin(float expRandMin);

    void setExpRandMax(float expRandMax);

    void setLevelDifference(float levelDifference);

    void setMaxAgility(float maxAgility);

    float getMaxHealth(RaceID, GameClassID, uint level);
    float getRecoveryHealth(RaceID, GameClassID);
    float getMaxMana(RaceID, GameClassID, uint exp);
    float getRecoveryMana(RaceID, GameClassID);
    float getRecoveryManaMeditation(RaceID, GameClassID);
    float getGoldDrop(uint maxHealthNPC);
    float getMaxGold(uint level);
    float getNextLevelLimit(uint level);
    float getExp(RaceID, GameClassID, uint level, uint enemyLevel);
    float getAdditionalExp(RaceID, GameClassID, uint level, uint enemyLevel);
    float getDamage(RaceID, GameClassID);
    bool canEvade(RaceID);
    float getDefense();
    float getTimeInSeconds(RaceID raceId, uint distance);

    void insertRace(RaceID id, RaceInfo info);

    void insertGameClass(GameClassID id, GameClassInfo info);
};


#endif //ARGENTUM_TALLER_GAMESTATSCONFIG_H
