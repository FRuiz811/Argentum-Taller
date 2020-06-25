#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H
#include <string>
#include <iostream>
#include "Position.h"
#include "GameObjectInfo.h"
#include "Identificators.h"

class GameObject{
protected:
    Position position;
    uint id{};
    std::string textureHashId;
    Direction direction;

public:
	GameObject();
	explicit GameObject(uint id);

	GameObject(GameObject&&) noexcept;
	GameObject& operator=(GameObject&& other)  noexcept;

    Position &getPosition();
    void setPosition(const Position &position);

    GameObjectInfo getGameObjectInfo();
    virtual void update() = 0;

    ~GameObject();
};

#endif
