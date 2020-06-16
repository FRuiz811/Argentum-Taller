#include "Raza.h"

Raza::Raza(int raza){ obtenerDatosIniciales(raza);}

void Raza::obtenerDatosIniciales(int raza){
	StatsJuego stats;	

	this->fRecuperacion = stats.fRazaRecuperacion[raza];
	this->fVida = stats.fRazaVida[raza];
	this->fMana = stats.fRazaMana[raza];
}

