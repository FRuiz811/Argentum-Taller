#ifndef CLASE_H
#define CLASE_H
#include <string>
#include "StatsJuego.h"
class Clase {
private: 
	void obtenerDatosIniciales(int clase);

public:
	float fRecuperacion;
	float fVida;
	float fMana;
	float fMeditacion;
	
	Clase();
	Clase(int clase);
};


#endif
