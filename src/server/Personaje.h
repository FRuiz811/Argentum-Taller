#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
//#include "Arma.h"
#include "ObjetoJuego.h"
#include "Ataque.h"
#include "Excepciones.h"
#include <iostream>
#include <cmath>
#include "Ecuacion.h"

class Personaje : public ObjetoJuego{
private: 
	//Inventario inventario;

	Arma arma;

	Ataque ataque;
	void corroborarAtaque(ObjetoJuego &atacado);
	
public: 
	//Arma armadura;
	//Arma escudo;
	//Arma casco;
	
	//ToDo: separar armadura-escudo-casco

	Personaje(int raza, int clase, Posicion posicion);
	void equiparArma(Arma arma);
	
	void atacar(ObjetoJuego &atacado);

	~Personaje();
	/*Destructor del Personaje.*/

private: 
	//bool esAtacable();
};

#endif
