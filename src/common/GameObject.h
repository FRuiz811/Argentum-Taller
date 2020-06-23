#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H
#include <string>
#include <iostream>
#include "Position.h"
#include "GameObjectInfo.h"

class GameObject{
protected:
    Position position;
    GameObjectInfo gameObjectInfo;
//  Estado

public:
	GameObject();
	explicit GameObject(Position);

	GameObject(GameObject&&) noexcept;
	GameObject& operator=(GameObject&& other)  noexcept;

    Position &getPosition();

    void setPosition(const Position &position);

    const GameObjectInfo &getGameObjectInfo() const;

    void setGameObjectInfo(const GameObjectInfo &gameObjectInfo);

    virtual void update() = 0;

    ~GameObject();
};

#endif
