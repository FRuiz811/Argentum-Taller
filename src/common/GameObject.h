#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H
#include <string>
#include <iostream>
#include "Position.h"
#include "GameObjectInfo.h"

class GameObject{
protected:
    Position position;
    uint id{};
    std::string textureHashId;

public:
	GameObject();
	explicit GameObject(uint id);

	GameObject(GameObject&&) noexcept;
	GameObject& operator=(GameObject&& other)  noexcept;

    Position &getPosition();

    void setPosition(const Position &position);

    virtual void update() = 0;

    ~GameObject();
};

#endif
