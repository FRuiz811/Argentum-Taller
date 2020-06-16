#ifndef CASILLERO_H
#define CASILLERO_H
#include "ObjetoJuego.h"
#include "Excepciones.h"
#include <functional>
#include <iostream>

class Casillero {
private: 
	bool vacio;
	ObjetoJuego* objeto;
public: 
	Casillero();

	void agregarObjeto(ObjetoJuego* objeto);

	ObjetoJuego* eliminarObjeto();

	ObjetoJuego* obtenerObjeto();

	bool estaVacio();

	~Casillero();
};

#endif
