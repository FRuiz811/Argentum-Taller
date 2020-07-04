#ifndef ARGENTUM_TALLER_BOARD_H
#define ARGENTUM_TALLER_BOARD_H


#include <vector>
#include <memory>
#include "Point.h"
#include "StaticObject.h"
#include "ObjectLayer.h"
#include "PlayerInfo.h"
#include "GameStats.h"
#include "GameStatsConfig.h"
#include "NestPoint.h"
#include "NestPointContainer.h"

class Board {
private:
    uint width{};
    uint heigth{};
    Point initialPoint;
    std::vector<StaticObject> collisionObjects;
    std::vector<StaticObject> cities;
    NestPointContainer nestPointContainer;
public:
    Board();
    Board(std::vector<ObjectLayer> objectLayers, uint width,
            uint height, uint8_t nestCreaturesLimit);

    virtual ~Board();

    bool checkCollisions(Position& position, uint id);

    Point &getInitialPoint();

    Point getNextAvailableNestPoint();
};


#endif //ARGENTUM_TALLER_BOARD_H
