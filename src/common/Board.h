#ifndef ARGENTUM_TALLER_BOARD_H
#define ARGENTUM_TALLER_BOARD_H


#include <vector>
#include <memory>
#include "Point.h"
#include "StaticObject.h"
#include "ObjectLayer.h"
#include "../client/PlayerInfo.h"
#include "GameStats.h"
#include "GameStatsConfig.h"

class Board {
private:
    uint width{};
    uint heigth{};
    Point initialPoint;
    std::vector<StaticObject> collisionObjects;
    std::vector<StaticObject> cities;
public:
    Board();
    Board(std::vector<ObjectLayer> objectLayers, uint width, uint height);

    virtual ~Board();

    void update(GameStatsConfig& gameStatsConfig);

    bool checkCollisions(Position& position, uint id);

    Point &getInitialPoint();
};


#endif //ARGENTUM_TALLER_BOARD_H
