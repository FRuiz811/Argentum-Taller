#include "Board.h"
#include "Collider.h"
#include "ObjectLayer.h"

Board::~Board() = default;

Board::Board() = default;

Board::Board(std::vector<ObjectLayer> objectLayers, uint width,
        uint height, uint8_t nestCreaturesLimit) :
        width(width), heigth(height), initialPoint(1125, 550)  {

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
                nestPoints.emplace_back(aCollisionObject.getPosition().getPoint(), nestCreaturesLimit);
            }
            nestPointContainer = NestPointContainer(nestPoints);
        }
    }
}

bool Board::checkCollisions(Position& aPosition, uint id) {
    bool isColliding = false;
    for (auto& collisionObject : collisionObjects) {
        if (Collider::checkCollision(aPosition, collisionObject.getPosition())) {
            isColliding = true;
            break;
        }
    }
    return isColliding;
}

Point &Board::getInitialPoint() {
    return initialPoint;
}

Point Board::getNextAvailableNestPoint() {
    return nestPointContainer.getNextNestPointAvailable();
}



