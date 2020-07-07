#ifndef ARGENTUM_TALLER_BOARD_H
#define ARGENTUM_TALLER_BOARD_H


#include <vector>
#include <memory>
#include "../common/Point.h"
#include "../common/StaticObject.h"
#include "../common/ObjectLayer.h"
#include "../common/PlayerInfo.h"
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

    bool checkCreaturesCollisions(BoardPosition& aBoardPosition, const Position& newPosition, uint id);

    Point &getInitialPoint();

    Point getInitialPointInNest(NestPoint& nestPoint);

    std::vector<uint> getCreaturesInNestPoint(uint nestId);

    bool isInsideNest(Position& aPosition, uint nestId);

    bool isInsideACity(Position& aPosition);

    uint isInsideANest(Position& aPosition);

    uint getIdFromPoint(Point& aPoint);

    NestPoint& getAvailableNestPoint();

    void addGameObjectPosition(uint id, BoardPosition& boardPosition);

    bool checkCollisionsAndCities(Position &position);

    void deleteGameObjectPosition(const uint id);
};


#endif //ARGENTUM_TALLER_BOARD_H
