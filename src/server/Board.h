#ifndef ARGENTUM_TALLER_BOARD_H
#define ARGENTUM_TALLER_BOARD_H


#include <vector>
#include <memory>
#include <queue>
#include "../common/Point.h"
#include "../common/StaticObject.h"
#include "../common/ObjectLayer.h"
#include "../common/PlayerInfo.h"
#include "GameStats.h"
#include "GameStatsConfig.h"
#include "Nest.h"
#include "NestContainer.h"
#include "Cell.h"
#include "../common/TiledMap.h"

class Board {
private:
    uint width{};
    uint height{};
    uint cols{}, rows{};
    Point initialPoint;
    NestContainer nestContainer;
    std::vector<std::vector<std::shared_ptr<Cell>>> cells;

    void addCity(StaticObject &city);
    std::tuple<int, int> convertPoint(const Point &point);
    void addCollisonObject(StaticObject &object);
    std::pair<int, int> getCorrectPosition(const std::shared_ptr<Cell>& aCell, Direction aDirection);
public:
    Board();

    Board(TiledMap &map, uint8_t nestCreaturesLimit);

    virtual ~Board();

    std::shared_ptr<Cell> getCellFromPoint(const Point& aPoint);

    Point getPointFromCell(const std::shared_ptr<Cell>& aCell);

    std::shared_ptr<Cell> getCell(uint x, uint y);

    std::shared_ptr<Cell> getInitialCell();

    std::vector<std::pair<uint8_t, std::shared_ptr<Cell>>> getAdjacents(std::tuple<uint, uint>, uint8_t distance);

    uint8_t getDistance(const std::shared_ptr<Cell>& firstCell, const std::shared_ptr<Cell>& secondCell);

    std::shared_ptr<Cell> getInitialCellInNest(Nest& nest);

    std::vector<uint> getCreaturesInNest(uint nestId);

    Nest& getAvailableNest();

    std::vector<std::shared_ptr<Cell>> setCellsInNest(const std::shared_ptr<Cell>& aNestCell, uint nestId);

    bool characterCanMove(const std::shared_ptr<Cell>& aCell, Direction aDirection);

    bool creatureCanMove(const std::shared_ptr<Cell>& aCell, Direction aDirection);

    std::shared_ptr<Cell> getNextCell(const std::shared_ptr<Cell>& aCell, Direction aDirection);

    std::shared_ptr<Cell> getBestCell(const std::shared_ptr<Cell>& actualCell, const std::shared_ptr<Cell>& DestinationCell);

    Direction getDirection(const std::shared_ptr<Cell>& actualCell, const std::shared_ptr<Cell>& DestinationCell);

    void removeCreatureFromNest(const std::shared_ptr<Cell>& aCell);

    int getAmountCreatures();

    std::shared_ptr<Cell> getNextEmptyCell(const std::shared_ptr<Cell>& aCell);

    std::shared_ptr<Cell> getCloserPriest(const std::shared_ptr<Cell>& aCell);

};


#endif //ARGENTUM_TALLER_BOARD_H
