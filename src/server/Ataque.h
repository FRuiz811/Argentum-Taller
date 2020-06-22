#ifndef ATAQUE_H
#define ATAQUE_H
#include "GameObject.h"
#include "Estado.h"
#include "Excepciones.h"
#include <functional>
#include <iostream>
#include "Ecuacion.h"
#include "StatsJuego.h"
#include "Arma.h"
#include "Defensa.h"

class Ataque {
private: 
	
public: 
	Ataque();

	float atacar(GameObject &atacado, Arma &arma, float nivel);

	~Ataque();
};

#endif
