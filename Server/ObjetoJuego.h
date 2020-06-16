#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H
#include <string>
#include <iostream>
#include "Estado.h"
#include "Movimiento.h"
#include "Posicion.h"
#include "Arma.h"

class ObjetoJuego{
protected: 
	Movimiento movimiento;

public: 
	
	Estado estado;
	//ObjetoJuego();
	ObjetoJuego(int raza, int clase, Posicion posicion);
	ObjetoJuego(Posicion posicion);
	int getCoordenadaX();

	int getCoordenadaY();

	ObjetoJuego(ObjetoJuego&& other);
    /* Constructor encargado de que el objeto pueda moverse, 
    //junto con el operador asignacion por movimiento.*/  

    ObjetoJuego& operator=(ObjetoJuego&& other);	
	/* Asignacion del operador '=' para que se pueda mover el ObjetoJuego a través 
	del mismo.*/ 

	bool operator==(const ObjetoJuego& other) const{
		return this->estado == other.estado;
	}

	~ObjetoJuego();
};

#endif
