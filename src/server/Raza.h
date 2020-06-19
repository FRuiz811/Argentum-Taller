#ifndef RAZA_H
#define RAZA_H
#include <string>
#include "StatsJuego.h"

class Raza {
private: 
	void obtenerDatosIniciales(int raza);

public:
	float fRecuperacion;
	float fVida;
	float fMana;

	Raza();
	Raza(int raza);
};


#endif
