#ifndef ARGENTUM_TALLER_GAMESTATSCONFIG_H
#define ARGENTUM_TALLER_GAMESTATSCONFIG_H

#include <unordered_map>
#include "GameStats.h"
#include "../common/Identificators.h"
#include <rapidjson/document.h>
#include <map>

class GameStatsConfig {
private:
    static std::unordered_map<RaceID, RaceInfo, std::hash<RaceID>> races;
    static std::unordered_map<GameClassID, GameClassInfo, std::hash<GameClassID>> gameClasses;
    static std::map<ItemsInventoryID, ItemInfo> items;
    static std::unordered_map<CreatureID, CreatureInfo, std::hash<CreatureID>> creatures;
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
    static uint8_t levelDifference;
    static float maxAgility;
    static uint8_t creaturesLimit;
    static uint8_t nestCreaturesLimit;
    static float distance;
    static int inventoryLimit;
    static int newbieLevel;
    RaceInfo createRaceInfo(rapidjson::Value &value);
    GameClassInfo createGameClass(rapidjson::Value &value);
    ItemInfo createItem(rapidjson::Value& value);
    CreatureInfo createCreatureInfo(rapidjson::Value &value);
public:
    GameStatsConfig();

    explicit GameStatsConfig(rapidjson::Document &json);

    virtual ~GameStatsConfig();
    static std::string getPort();
    static float getMaxHealth(RaceID raceId, GameClassID gameClassId, uint level);
    static float getMaxHealth(CreatureID creatureId, uint level);
    static float getRecoveryHealth(RaceID raceId);
    static float getMaxMana(RaceID raceId, GameClassID gameClassId, uint level);
    static float getRecoveryMana(RaceID raceId);
    static float getRecoveryManaMeditation(RaceID raceId, GameClassID gameClassId);
    static float getGoldDrop(CreatureID creatureId, uint level);
    static float getMaxGold(uint level);
    static float getNextLevelLimit(uint level);
    static float getExp(float damage, uint level, uint enemyLevel);
    static float getAdditionalExp(float damage, float enemyMaxLife, uint level, uint enemyLevel);
    static float getDamage(RaceID race, WeaponID weaponId);
    static float getDamage(CreatureID creatureId);
    static bool canEvade(RaceID raceId);
    static bool canEvade(CreatureID creatureId);
    static float getDefense(BodyID bodyId, ShieldID shieldId, HelmetID helmetId);
    static float getDefense(CreatureID creatureId);
    static std::map<ItemsInventoryID,ItemInfo> getItems();
    static uint8_t getAmountSteps(RaceID raceId);
    static uint8_t getAmountSteps(CreatureID creatureId);
    static uint8_t getCreaturesLimit();
    static const ItemInfo getItem(ItemsInventoryID id);
    static uint8_t getNestCreatureLimit();
    static float getDistance();
    static int getInventoryLimit();
    static int getWeaponDistance(WeaponID aWeaponId);
    static int getWeaponCost(WeaponID aWeaponId);
    static bool canAttack(int level, int enemyLevel);
    static bool isNewbie(int level);
    static float restoreHealth(WeaponID aWeaponId);
};


#endif //ARGENTUM_TALLER_GAMESTATSCONFIG_H
