#ifndef CRIATURA_H
#define CRIATURA_H
#include "GameObject.h"

class Criatura : public GameObject{
private: 
	//Ataque ataque;
	//Movimiento movimiento;

public: 
	Criatura(Position posicion);
	/*Constructor de la Criatura.*/
	//Position getPosicion(){}
	
	~Criatura();
	/*Destructor de la Criatura.*/
};

#endif
