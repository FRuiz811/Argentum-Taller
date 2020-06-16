#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include <iostream>
#include <map>
#include "Posicion.h"
#include "Casillero.h"


class Tablero {
private: 
	std::map<Posicion, Casillero> casilleros;
	
	//int tamanioTablero;
public: 
	//Tablero(int tamanio);
	Tablero();
	~Tablero();
};

#endif
