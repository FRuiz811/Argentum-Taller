#ifndef ESTADO_H
#define ESTADO_H
#include "StatsJuego.h"
#include <iostream>
#include "Raza.h"
#include "Clase.h"
#include "Ecuacion.h"
#include <cmath>

class Estado{
private: 
	float nivel;
	float constitucion;
	float vida;
	float inteligencia;
	float agilidad;
	//int danio;
	float fuerza;
	float experiencia;

	Raza raza;
	Clase clase;

	void obtenerEstados(int numRaza, int numClase);
	void obtenerEstadosCriaturas();

public: 
	Estado(); //Para NPCServer
	Estado(int numRaza, int numClase); //Para personas

	float getAgilidad();
	float getConstitucion();
	float getInteligencia();
	int getNivel();
	bool sigueVivo();
	void setearAMuerto();
	float getVida();
	float getFClaseVida();
	float getFRazaVida();
	/*Constructor del Estado.*/
	void restarVida(float danio);
	void updateNivel(float experiencia);

	~Estado();
	/*Destructor del Estado.*/

	bool operator==(const Estado& other) const{
		float epsilon = 0.01f;
		if(fabs(this->nivel - other.nivel) <= epsilon && 
			fabs(this->constitucion - other.constitucion) <= epsilon  &&
			fabs(this->vida - other.vida) <= epsilon  && 
			fabs(this->inteligencia - other.inteligencia) <= epsilon  &&
			fabs(this->agilidad - other.agilidad) <= epsilon  && 
			fabs(this->fuerza - other.fuerza) <= epsilon  &&
			fabs(this->experiencia - other.experiencia) <= epsilon ) return true;
		return false;
	}
};

#endif
