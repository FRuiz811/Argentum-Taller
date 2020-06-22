#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include <iostream>
#include <map>
#include "Position.h"
#include "Cell.h"


class Tablero {
private: 
	std::map<Position, Cell> casilleros;
	
	//int tamanioTablero;
public: 
	//Tablero(int tamanio);
	Tablero();
	~Tablero();
};

#endif
