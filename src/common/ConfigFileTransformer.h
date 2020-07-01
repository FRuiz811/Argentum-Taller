#ifndef ARGENTUM_TALLER_CONFIGFILETRANSFORMER_H
#define ARGENTUM_TALLER_CONFIGFILETRANSFORMER_H


#include <rapidjson/document.h>
#include "GameStatsConfig.h"

class ConfigFileTransformer {
private:
    static RaceInfo createRaceInfo(rapidjson::Value &value);
    static GameClassInfo createGameClass(rapidjson::Value &value);
public:
    ConfigFileTransformer();

    virtual ~ConfigFileTransformer();

    static GameStatsConfig transform(rapidjson::Document&);
};


#endif //ARGENTUM_TALLER_CONFIGFILETRANSFORMER_H
