#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H
#include <string>
#include <iostream>
#include "../server/Estado.h"
#include "../server/Movimiento.h"
#include "Position.h"
#include "../server/Arma.h"

class GameObject{
protected: 
//	Movimiento movimiento;
    Position position;

public:
	GameObject();
	GameObject(Position);
	GameObject(GameObject&&) noexcept;

    GameObject& operator=(GameObject&& other)  noexcept;

    Position &getPosition();

    void setPosition(const Position &position);

    ~GameObject();
};

#endif
