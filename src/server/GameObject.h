#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H
#include <string>
#include <iostream>
#include "Estado.h"
#include "Movimiento.h"
#include "Position.h"
#include "Arma.h"

class GameObject{
protected: 
//	Movimiento movimiento;
    Position position;

public:
	GameObject();
	GameObject(Position);
	GameObject(GameObject&&);
    /* Constructor encargado de que el objeto pueda moverse, 
    //junto con el operador asignacion por movimiento.*/  

    GameObject& operator=(GameObject&& other);
	/* Asignacion del operador '=' para que se pueda mover el GameObject a través
	del mismo.*/ 

	bool operator==(const GameObject& other) const{
		return this->estado == other.estado;
	}

    const Position &getPosition() const;

    ~GameObject();
};

#endif
