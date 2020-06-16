#include "Movimiento.h"

Movimiento::Movimiento() : posicionActual(Posicion(0,0)){}

Movimiento::Movimiento(Posicion pos) : posicionActual(pos){}

int Movimiento::getCoordenadaX(){
	return this->posicionActual.getCoordenadaX();
}

int Movimiento::getCoordenadaY(){
	return this->posicionActual.getCoordenadaY();
}


Movimiento::~Movimiento(){}
