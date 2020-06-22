#ifndef CASILLERO_H
#define CASILLERO_H
#include "GameObject.h"
#include "Excepciones.h"
#include <functional>
#include <iostream>

class Cell {
private: 
	bool vacio;
	GameObject* objeto;
public: 
	Cell();

	void agregarObjeto(GameObject* objeto);

	GameObject* eliminarObjeto();

	GameObject* obtenerObjeto();

	bool estaVacio();

	~Cell();
};

#endif
