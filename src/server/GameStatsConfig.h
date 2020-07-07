#ifndef ARGENTUM_TALLER_GAMESTATSCONFIG_H
#define ARGENTUM_TALLER_GAMESTATSCONFIG_H

#include <unordered_map>
#include "GameStats.h"
#include "../common/Identificators.h"
#include <rapidjson/document.h>

class GameStatsConfig {
private:
    std::unordered_map<RaceID, RaceInfo, std::hash<RaceID>> races;
    std::unordered_map<GameClassID, GameClassInfo, std::hash<GameClassID>> gameClasses;
    std::unordered_map<ItemsInventoryID, ItemInfo, std::hash<ItemsInventoryID>> items;
    std::string port;
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
    float distance{};
public:
    GameStatsConfig();

    explicit GameStatsConfig(rapidjson::Document &json);

    virtual ~GameStatsConfig();
    std::string getPort() const;
    float getMaxHealth(RaceID, GameClassID, uint level) const;
    float getRecoveryHealth(RaceID, GameClassID) const;
    float getMaxMana(RaceID, GameClassID, uint level) const;
    float getRecoveryMana(RaceID, GameClassID) const;
    float getRecoveryManaMeditation(RaceID, GameClassID) const;
    float getGoldDrop(uint maxHealthNPC) const;
    float getMaxGold(uint level) const;
    float getNextLevelLimit(uint level) const;
    float getExp(RaceID, GameClassID, uint level, uint enemyLevel) const;
    float getAdditionalExp(RaceID, GameClassID, uint level, uint enemyLevel) const;
    float getDamage(RaceID race, WeaponID weaponId) const;
    float getDamage(CreatureID creatureId) const;
    bool canEvade(RaceID) const;
    float getDefense(BodyID bodyId, ShieldID shieldId, HelmetID helmetId) const;
    std::unordered_map<ItemsInventoryID,ItemInfo> getItems() const;
    uint8_t getAmountSteps(RaceID raceId) const;
    uint8_t getAmountSteps(CreatureID creatureId) const;
    uint8_t getCreaturesLimit() const;
    RaceInfo createRaceInfo(rapidjson::Value &value);
    GameClassInfo createGameClass(rapidjson::Value &value);
    ItemInfo createItem(rapidjson::Value& value);
    uint8_t getNestCreatureLimit() const ;
    float getDistance() const;
};


#endif //ARGENTUM_TALLER_GAMESTATSCONFIG_H
