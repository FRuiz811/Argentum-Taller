#include "Posicion.h"

Posicion::Posicion(int coordenadaX, int coordenadaY) : coordenadaX(coordenadaX), coordenadaY(coordenadaY){}

int Posicion::getCoordenadaX(){
	return coordenadaX;
}

int Posicion::getCoordenadaY(){
	return coordenadaY;
}

Posicion::~Posicion(){}
