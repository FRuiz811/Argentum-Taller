#ifndef ARMA_H
#define ARMA_H
#include "GameObject.h"
#include "Excepciones.h"
#include <functional>
#include <iostream>

class Arma {
private: 
	bool aDistancia;
	float danioMin;
	float danioMax;
public: 
	Arma();

	bool esArmaDistancia();
	float getDanioMin();
	float getDanioMax();
	
	~Arma();
};

#endif
