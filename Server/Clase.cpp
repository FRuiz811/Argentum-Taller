#include "Clase.h"

Clase::Clase(int clase){ obtenerDatosIniciales(clase);}

void Clase::obtenerDatosIniciales(int clase){
	StatsJuego stats;	

	this->fRecuperacion = stats.fClaseRecuperacion[clase];
	this->fVida = stats.fClaseVida[clase];
	this->fMana = stats.fClaseMana[clase];
	this->fMeditacion = stats.fClaseMeditacion[clase];
}

