#include "ConfigFileTransformer.h"

ConfigFileTransformer::ConfigFileTransformer() = default;

ConfigFileTransformer::~ConfigFileTransformer() = default;

GameStatsConfig ConfigFileTransformer::transform(rapidjson::Document &json) {
    GameStatsConfig gameStatsConfig;

    gameStatsConfig.setGoldRandMin(json["goldRandMin"].GetFloat());
    gameStatsConfig.setGoldRandMax(json["goldRandMax"].GetFloat());
    gameStatsConfig.setGoldMaxMult(json["goldMaxMult"].GetFloat());
    gameStatsConfig.setGoldMaxPot(json["goldMaxPot"].GetFloat());
    gameStatsConfig.setExpRandMin(json["expRandMin"].GetFloat());
    gameStatsConfig.setExpRandMax(json["expRandMax"].GetFloat());
    gameStatsConfig.setExpMaxMult(json["expMaxMult"].GetFloat());
    gameStatsConfig.setExpMaxPot(json["expMaxPot"].GetFloat());
    gameStatsConfig.setEvadeRandMin(json["evadeRandMin"].GetFloat());
    gameStatsConfig.setEvadeRandMax(json["evadeRandMax"].GetFloat());
    gameStatsConfig.setEvadeProbability(json["evadeProbability"].GetFloat());
    gameStatsConfig.setLevelDifference(json["levelDifference"].GetFloat());
    gameStatsConfig.setMaxAgility(json["maxAgility"].GetFloat());


    rapidjson::Value::Array races = json["races"].GetArray();
    for (auto &aRace : races) {
        gameStatsConfig.insertRace(RaceID(aRace["id"].GetInt()), createRaceInfo(aRace));
    }
    rapidjson::Value::Array gameClasses = json["classes"].GetArray();
    for (auto &aGameClass : gameClasses) {
        gameStatsConfig.insertGameClass(GameClassID(aGameClass["id"].GetInt()), createGameClass(aGameClass));
    }
    return gameStatsConfig;
}

RaceInfo ConfigFileTransformer::createRaceInfo(rapidjson::Value &value) {
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

GameClassInfo ConfigFileTransformer::createGameClass(rapidjson::Value &value) {
    GameClassInfo aGameClassInfo{};
    aGameClassInfo.health = value["health"].GetInt();
    aGameClassInfo.mana = value["mana"].GetInt();
    aGameClassInfo.meditation = value["meditation"].GetInt();
    return aGameClassInfo;
}
