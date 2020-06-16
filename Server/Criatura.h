#ifndef CRIATURA_H
#define CRIATURA_H
#include "ObjetoJuego.h"

class Criatura : public ObjetoJuego{
private: 
	//Ataque ataque;
	//Movimiento movimiento;

public: 
	Criatura(Posicion posicion);
	/*Constructor de la Criatura.*/
	//Posicion getPosicion(){}
	
	~Criatura();
	/*Destructor de la Criatura.*/
};

#endif
