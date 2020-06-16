#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include "Posicion.h"
#include "Excepciones.h"
#include <functional>
#include <iostream>

class Movimiento {
private: 
	Posicion posicionActual;
public: 
	Movimiento();
	Movimiento(Posicion pos);

	int getCoordenadaY();
	int getCoordenadaX();

	//ToDo: Mover arriba-Abajo...
	~Movimiento();
};

#endif
