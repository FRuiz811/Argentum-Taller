#include "Board.h"
#include "Collider.h"

Board::~Board() = default;

Board::Board() = default;

Board::Board(std::vector<ObjectLayer> objectLayers, uint width,
        uint height, uint8_t nestCreaturesLimit) :
        width(width), height(height), initialPoint(1125, 550) {

    uint nestPointIdCounter = 1;
    for (auto&& anObjectLayer : objectLayers) {
        if (anObjectLayer.getName() == "cities") {
            for (StaticObject& aCity : anObjectLayer.getObjects()) {
                cities.push_back(aCity);
            }
        } else if (anObjectLayer.getName() == "collisionObjects") {
            for (StaticObject& aCollisionObject : anObjectLayer.getObjects()) {
                collisionObjects.push_back(aCollisionObject);
            }
        } else if (anObjectLayer.getName() == "nestPoints") {
            std::vector<NestPoint> nestPoints;
            for (StaticObject& aCollisionObject : anObjectLayer.getObjects()) {
                nestPoints.emplace_back(aCollisionObject.getPosition().getPoint(), width, height, nestCreaturesLimit, nestPointIdCounter++);
            }
            nestPointContainer = NestPointContainer(nestPoints);
        }
    }
}

bool Board::checkCollisions(BoardPosition& aBoardPosition, Position &newPosition, uint id) {
    bool isColliding = false;
    if (newPosition.getBottom() > height || newPosition.getTop() < 0 || newPosition.getLeft() < 0 || newPosition.getRight() > width) {
        isColliding = true;
    }
    for (auto& gameObject : gameObjectPositions) {
        if (gameObject.first == id) {
            continue;
        }
        if (Collider::checkCollision(newPosition, gameObject.second.getPosition())) {
            isColliding = true;
            break;
        }
    }
    for (auto& collisionObject : collisionObjects) {
        if (Collider::checkStaticCollision(newPosition, collisionObject.getPosition())) {
            isColliding = true;
            break;
        }
    }
    return isColliding;
}

Point &Board::getInitialPoint() {
    return initialPoint;
}

NestPoint& Board::getAvailableNestPoint() {
    return nestPointContainer.getNextNestPointAvailable();
}

bool Board::checkCollisionsAndCities(Position &aPosition) {
    bool isColliding = false;
    for (auto& collisionObject : collisionObjects) {
        if (Collider::checkStaticCollision(aPosition, collisionObject.getPosition())) {
            isColliding = true;
            break;
        }
    }
    for (auto& collisionObject : cities) {
        if (Collider::checkStaticCollision(aPosition, collisionObject.getPosition())) {
            isColliding = true;
            break;
        }
    }
    for (auto& aGameObjectPosition : gameObjectPositions) {
        if (Collider::checkCollision(aPosition, aGameObjectPosition.second.getPosition())) {
            isColliding = true;
            break;
        }
    }
    return isColliding;
}

void Board::addGameObjectPosition(uint id, BoardPosition &boardPosition) {
    gameObjectPositions.insert(std::pair<uint, BoardPosition&>(id, boardPosition));
}

std::vector<uint> Board::getCreaturesInNestPoint(uint nestId) {
    NestPoint& nestPoint = nestPointContainer.getNestPoint(nestId);
    return nestPoint.getCreatures();
}

Point Board::getInitialPointInNest(NestPoint &nestPoint) {
    std::vector<Position> posiblePositions = nestPoint.getPosiblePositions();
    Point aPoint(0.0, 0.0);
    for (auto &aPosition : posiblePositions) {
        if(!checkCollisionsAndCities(aPosition)) {
            aPoint = aPosition.getPoint();
            break;
        }
    }
    return aPoint;
}

bool Board::checkCreaturesCollisions(BoardPosition& aBoardPosition, const Position& newPosition, uint id) {
    bool isColliding = false;
    Position& nestPointPosition = nestPointContainer.getNestPoint(aBoardPosition.getNestId()).getPosition();
    if (newPosition.getBottom() > nestPointPosition.getBottom() ||
    newPosition.getTop() < nestPointPosition.getTop() ||
    newPosition.getLeft() < nestPointPosition.getLeft() ||
    newPosition.getRight() > nestPointPosition.getRight()) {
        isColliding = true;
    }
    for (auto& gameObject : gameObjectPositions) {
        if (gameObject.first == id) {
            continue;
        }
        if (Collider::checkCollision(newPosition, gameObject.second.getPosition())) {
            isColliding = true;
            break;
        }
    }
    for (auto& collisionObject : collisionObjects) {
        if (Collider::checkStaticCollision(newPosition, collisionObject.getPosition())) {
            isColliding = true;
            break;
        }
    }
    for (auto& city : cities) {
        if (Collider::checkStaticCollision(newPosition, city.getPosition())) {
            isColliding = true;
            break;
        }
    }
    return isColliding;
}

bool Board::isInsideNest(Position &aPosition, uint nestId) {
    Position& nestPointPosition = nestPointContainer.getNestPoint(nestId).getPosition();
    return Collider::checkStaticCollision(aPosition, nestPointPosition);
}

void Board::deleteGameObjectPosition(uint id) {
    this->gameObjectPositions.erase(id);
}

bool Board::isInsideACity(Position& aPosition) {
    bool insideCity = false;
    for (auto& city : cities) {
        if (Collider::checkStaticCollision(aPosition, city.getPosition())) {
            insideCity = true;
            break;
        }
    }
    return insideCity;
}

uint Board::isInsideANest(Position &aPosition) {
    uint nestId = 0;
    for (auto& aNestPoint : nestPointContainer.getNestPoints()) {
        if (Collider::checkStaticCollision(aPosition, aNestPoint.getPosition())) {
            nestId = aNestPoint.getNestId();
            break;
        }
    }
    return nestId;
}

uint Board::getIdFromPoint(Point& aPoint) {
    Position newPosition = Position(aPoint, 1, 1);
    uint gameObjectId = 0;
    for (auto& gameObject : gameObjectPositions) {
        if (Collider::checkCollision(newPosition, gameObject.second.getPosition())) {
            gameObjectId = gameObject.first;
            break;
        }
    }
    return gameObjectId;
}
