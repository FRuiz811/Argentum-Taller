#ifndef ARGENTUM_TALLER_GAMESTATSCONFIG_H
#define ARGENTUM_TALLER_GAMESTATSCONFIG_H

#include <unordered_map>
#include "GameStats.h"
#include "../common/Identificators.h"
#include <rapidjson/document.h>

class GameStatsConfig {
private:
    static std::unordered_map<RaceID, RaceInfo, std::hash<RaceID>> races;
    static std::unordered_map<GameClassID, GameClassInfo, std::hash<GameClassID>> gameClasses;
    static std::unordered_map<ItemsInventoryID, ItemInfo, std::hash<ItemsInventoryID>> items;
    static std::string port;
    static float goldRandMin;
    static float goldRandMax;
    static float goldMaxMult;
    static float goldMaxPot;
    static float expMaxMult;
    static float expMaxPot;
    static float evadeRandMin;
    static float evadeRandMax;
    static float evadeProbability;
    static float expRandMin;
    static float expRandMax;
    static float levelDifference;
    static float maxAgility;
    static uint8_t creaturesLimit;
    static uint8_t nestCreaturesLimit;
    static float distance;
    RaceInfo createRaceInfo(rapidjson::Value &value);
    GameClassInfo createGameClass(rapidjson::Value &value);
    ItemInfo createItem(rapidjson::Value& value);
public:
    GameStatsConfig();

    explicit GameStatsConfig(rapidjson::Document &json);

    virtual ~GameStatsConfig();
    static std::string getPort();
    static float getMaxHealth(RaceID, GameClassID, uint level);
    static float getRecoveryHealth(RaceID, GameClassID);
    static float getMaxMana(RaceID, GameClassID, uint level);
    static float getRecoveryMana(RaceID, GameClassID);
    static float getRecoveryManaMeditation(RaceID, GameClassID);
    static float getGoldDrop(uint maxHealthNPC);
    static float getMaxGold(uint level);
    static float getNextLevelLimit(uint level);
    static float getExp(RaceID, GameClassID, uint level, uint enemyLevel);
    static float getAdditionalExp(RaceID, GameClassID, uint level, uint enemyLevel);
    static float getDamage(RaceID race, WeaponID weaponId);
    static float getDamage(CreatureID creatureId);
    static bool canEvade(RaceID);
    static float getDefense(BodyID bodyId, ShieldID shieldId, HelmetID helmetId);
    static float getDefense(CreatureID creatureId);
    static std::unordered_map<ItemsInventoryID,ItemInfo> getItems();
    static uint8_t getAmountSteps(RaceID raceId);
    static uint8_t getAmountSteps(CreatureID creatureId);
    static uint8_t getCreaturesLimit();
    static const ItemInfo getItem(ItemsInventoryID id);
    static uint8_t getNestCreatureLimit();
    static float getDistance();
};


#endif //ARGENTUM_TALLER_GAMESTATSCONFIG_H
