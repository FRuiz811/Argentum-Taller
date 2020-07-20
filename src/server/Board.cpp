#include "Board.h"
#include <memory>
#include <cstdlib>

Board::~Board() = default;

Board::Board() = default;

Board::Board(TiledMap &map, uint8_t nestCreaturesLimit) : initialPoint(1125, 550) {
    cols = map.getWidth();
    rows = map.getHeight();
    height = map.getHeight() * map.getTileHeight();
    width = map.getWidth() * map.getTileWidth();
    uint nestIdCounter = 1;
    for (size_t i = 0; i < rows; ++i) {
        std::vector<std::shared_ptr<Cell>> cellsRows;
        for (size_t j = 0; j < cols; ++j) {
            cellsRows.push_back(std::make_shared<Cell>(i, j));
        }
        cells.push_back(cellsRows);
    }
    for (auto&& anObjectLayer : map.getObjectLayers()) {
        if (anObjectLayer.getName() == "cities") {
            for (StaticObject& aCity : anObjectLayer.getObjects()) {
                addCity(aCity);
            }
        } else if (anObjectLayer.getName() == "collisionObjects") {
            for (StaticObject &aCollisionObject : anObjectLayer.getObjects()) {
                addCollisonObject(aCollisionObject);
            }
        } else if (anObjectLayer.getName() == "nestPoints") {
            std::vector<Nest> nests;
            std::shared_ptr<Cell> aCell;
            uint nestId;
            for (StaticObject& aNest : anObjectLayer.getObjects()) {
                nestId = nestIdCounter++;
                aCell = getCellFromPoint(aNest.getTopLeft());
                nests.emplace_back(nestCreaturesLimit, nestId, setCellsInNest(aCell, nestId));
            }
            nestContainer = NestContainer(nests);
        }
    }
}

Nest& Board::getAvailableNest() {
    return nestContainer.getNextNestAvailable();
}

std::vector<uint> Board::getCreaturesInNest(uint nestId) {
    Nest& nest = nestContainer.getNest(nestId);
    return nest.getCreatures();
}

void Board::addCity(StaticObject &city) {
    std::tuple<int, int> topLeft = convertPoint(city.getTopLeft());
    std::tuple<int, int> bottomRight = convertPoint(city.getBottomRight());
    for (int i = std::get<0>(topLeft); i < std::get<0>(bottomRight); ++i) {
        for (int j = std::get<1>(topLeft); j < std::get<1>(bottomRight); ++j) {
            cells[i][j]->setCity(true);
        }
    }
}

std::tuple<int, int> Board::convertPoint(const Point &point) {
    int x = point.x / (width / cols);
    int y  = point.y / (height / rows);
    return std::make_tuple(x, y);
}

void Board::addCollisonObject(StaticObject &collisionObject) {
    std::tuple<int, int> topLeft = convertPoint(collisionObject.getTopLeft());
    std::tuple<int, int> bottomRight = convertPoint(collisionObject.getBottomRight());
    int diffX = std::get<0>(bottomRight) - std::get<0>(topLeft);
    int diffY = std::get<1>(bottomRight) - std::get<1>(topLeft);
    for (int i = std::get<0>(topLeft); diffX > 0 ? i < std::get<0>(bottomRight) : i <= std::get<0>(bottomRight); ++i) {
        for (int j = std::get<1>(topLeft); diffY > 0 ? j < std::get<1>(bottomRight) : j <= std::get<1>(bottomRight); ++j) {
            cells[i][j]->setEmpty(false);
        }
    }
}

std::shared_ptr<Cell> Board::getCellFromPoint(const Point &aPoint) {
    std::tuple<uint, uint> position = convertPoint(aPoint);
    return cells[std::get<0>(position)][std::get<1>(position)];
}

std::shared_ptr<Cell> Board::getCell(uint x, uint y) {
    return cells[x][y];
}

std::shared_ptr<Cell> Board::getInitialCell() {
    std::shared_ptr<Cell> cell = getCellFromPoint(initialPoint);
    if (!cell->isEmpty()) {
        for (auto &adjacent : getAdjacents(convertPoint(initialPoint), 4)) {
            if (adjacent.second->isEmpty()) {
                cell = adjacent.second;
                break;
            }
        }
    }
    return cell;
}

std::vector<std::pair<uint8_t, std::shared_ptr<Cell>>> Board::getAdjacents(std::tuple<uint, uint> position, uint8_t distance) {
    std::vector<std::pair<uint8_t, std::shared_ptr<Cell>>> adjacents;
    uint x = std::get<0>(position);
    uint y = std::get<1>(position);
    std::shared_ptr<Cell> originCell = getCell(x, y);
    uint leftLimitX = x - distance >= 0 ? x - distance : 0;
    uint rightLimitX = x + distance < cols ? x + distance : cols - 1;
    uint leftLimitY = y - distance >= 0 ? y - distance : 0;
    uint rightLimitY = y + distance < rows ? y + distance : rows - 1;
    std::shared_ptr<Cell> aCell;
    for (size_t i = leftLimitX; i <= rightLimitX; ++i) {
        for (size_t j = leftLimitY; j <= rightLimitY; ++j) {
            if (i == x && j == y) {
                continue;
            }
            aCell = getCell(i, j);
            uint8_t aDistance = getDistance(originCell, aCell);
            if (aDistance <= distance) {
                adjacents.emplace_back(aDistance, aCell);
            }
        }
    }
    std::sort_heap(adjacents.begin(), adjacents.end());
    return adjacents;
}

uint8_t Board::getDistance(const std::shared_ptr<Cell>& firstCell, const std::shared_ptr<Cell>& secondCell) {
    return std::abs(int(firstCell->getX() - secondCell->getX())) + std::abs(int(firstCell->getY() - secondCell->getY()));
}

Point Board::getPointFromCell(const std::shared_ptr<Cell>& aCell) {
    return Point(aCell->getX() * (width/cols), aCell->getY() * (height/rows));
}

std::shared_ptr<Cell> Board::getInitialCellInNest(Nest &nest) {
    return nest.getFreeCell();
}

std::vector<std::shared_ptr<Cell>> Board::setCellsInNest(const std::shared_ptr<Cell>& aNestCell, uint nestId) {
    std::vector<std::shared_ptr<Cell>> cellInsideNest;
    uint distance = 8;
    uint leftLimitX = int(aNestCell->getX() - distance) >= 0 ? aNestCell->getX() - distance : 0;
    uint rightLimitX = aNestCell->getX() + distance < cols ? aNestCell->getX() + distance : cols - 1;
    uint leftLimitY = int(aNestCell->getY() - distance) >= 0 ? aNestCell->getY() - distance : 0;
    uint rightLimitY = aNestCell->getY() + distance < rows ? aNestCell->getY() + distance : rows - 1;
    std::shared_ptr<Cell> aCell;
    for (size_t i = leftLimitY; i <= rightLimitY; ++i) {
        for (size_t j = leftLimitX; j <= rightLimitX; ++j) {
            aCell = getCell(i, j);
            if (!aCell->isCity()) {
                aCell->setNestId(nestId);
                cellInsideNest.push_back(aCell);
            }
        }
    }
    return cellInsideNest;
}

bool Board::characterCanMove(const std::shared_ptr<Cell> &aCell, Direction aDirection) {
    bool canMove = false;
    std::pair<uint, uint> aPosition = getCorrectPosition(aCell, aDirection);
    if (aPosition.first >= 0 && aPosition.first < cols && aPosition.second >= 0 && aPosition.second < rows) {
        canMove = getCell(aPosition.first, aPosition.second)->isEmpty();
    }
    return canMove;
}

std::shared_ptr<Cell> Board::getNextCell(const std::shared_ptr<Cell> &aCell, Direction aDirection) {
    std::pair<uint, uint> aPosition = getCorrectPosition(aCell, aDirection);
    return getCell(aPosition.first, aPosition.second);
}

bool Board::creatureCanMove(const std::shared_ptr<Cell> &aCell, Direction aDirection) {
    bool canMove = false;
    std::pair<uint, uint> aPosition = getCorrectPosition(aCell, aDirection);
    if (aPosition.first >= 0 && aPosition.first < cols && aPosition.second >= 0 && aPosition.second < rows) {
        std::shared_ptr<Cell> nestCell = getCell(aPosition.first, aPosition.second);
        canMove = nestCell->isEmpty() && nestCell->getNestId() == aCell->getNestId();
    }
    return canMove;
}

std::pair<int, int> Board::getCorrectPosition(const std::shared_ptr<Cell>& aCell, Direction aDirection) {
    int x = aCell->getX();
    int y = aCell->getY();
    switch(aDirection) {
        case Direction::up:
            y --;
            break;
        case Direction::down:
            y ++;
            break;
        case Direction::left:
            x --;
            break;
        case Direction::right:
            x ++;
            break;
    }
    return {x, y};
}

std::shared_ptr<Cell> Board::getBestCell(const std::shared_ptr<Cell>& actualCell, const std::shared_ptr<Cell>& destinationCell, bool overstepNest) {
    uint distance = 0;
    std::shared_ptr<Cell> bestCell = actualCell;
    for (auto &adjacent : getAdjacents(actualCell->getCoord(), 1)) {
        uint adjacentDistance = getDistance(adjacent.second, destinationCell);
        if (overstepNest || adjacent.second->getNestId() == actualCell->getNestId()) {
            if (adjacent.second->isEmpty() && (distance > adjacentDistance || distance == 0)) {
                bestCell = adjacent.second;
                distance = adjacentDistance;
            }
        }
    }
    return bestCell;
}

Direction Board::getDirection(const std::shared_ptr<Cell>& actualCell, const std::shared_ptr<Cell>& destinationCell) {
    Direction aDirection;
    if (actualCell->getX() > destinationCell->getX()) {
        aDirection = Direction::left;
    }
    if (actualCell->getX() < destinationCell->getX()) {
        aDirection = Direction::right;
    }
    if (actualCell->getY() > destinationCell->getY()) {
        aDirection = Direction::up;
    }
    if (actualCell->getY() < destinationCell->getY()) {
        aDirection = Direction::down;
    }
    return aDirection;
}

void Board::removeCreatureFromNest(const std::shared_ptr<Cell>& aCell) {
    Nest &nest = nestContainer.getNest(aCell->getNestId());
    nest.removeCreature(aCell->getGameObjectId());
}

int Board::getAmountCreatures() {
    return nestContainer.getAmountCreatures();
}

std::shared_ptr<Cell> Board::getNextEmptyCell(const std::shared_ptr<Cell> &aCell) {
    std::shared_ptr<Cell> cell = aCell;
    uint distance = 0;
    while (!cell->isEmpty() || cell->hasItem()) {
        distance++;
        for (auto &adjacent : getAdjacents(aCell->getCoord(), distance)) {
            if (adjacent.second->isEmpty() && !adjacent.second->hasItem()) {
                cell = adjacent.second;
                break;
            }
        }
    }
    return cell;
}

std::shared_ptr<Cell> Board::getCloserPriest(const std::shared_ptr<Cell>& aCell) {
    std::shared_ptr<Cell> chosenCell;
    std::shared_ptr<Cell> aCellPriest;
    uint8_t minDistance = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            aCellPriest = getCell(i, j);
            if (aCellPriest->isPriest()) {
                if (minDistance == 0 || minDistance > getDistance(aCellPriest, aCell)) {
                    minDistance = getDistance(aCellPriest, aCell);
                    chosenCell = aCellPriest;
                }
            }
        }
    }
    return chosenCell;
}
