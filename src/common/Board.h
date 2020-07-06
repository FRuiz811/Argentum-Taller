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
#include "NestPoint.h"
#include "NestPointContainer.h"
#include "BoardPosition.h"

class Board {
private:
    uint width{};
    uint height{};
    Point initialPoint;
    std::vector<StaticObject> collisionObjects;
    std::vector<StaticObject> cities;
    NestPointContainer nestPointContainer;
    std::unordered_map<uint, BoardPosition&, std::hash<uint>> gameObjectPositions;
public:
    Board();

    Board(std::vector<ObjectLayer> objectLayers, uint width,
            uint height, uint8_t nestCreaturesLimit);

    virtual ~Board();

    bool checkCollisions(BoardPosition& aBoardPosition, Position& newPosition, uint id);

    bool checkCreaturesCollisions(BoardPosition& aBoardPosition, Position& newPosition, uint id);

    Point &getInitialPoint();

    Point getInitialPointInNest(NestPoint& nestPoint);

    std::vector<uint> getCreaturesInNestPoint(uint nestId);

    NestPoint& getAvailableNestPoint();

    void addGameObjectPosition(uint id, BoardPosition& boardPosition);

    bool checkCollisionsAndCities(Position &position);
};


#endif //ARGENTUM_TALLER_BOARD_H
