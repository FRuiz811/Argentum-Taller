#ifndef DEFENSA_H
#define DEFENSA_H
#include "ObjetoJuego.h"
#include "Excepciones.h"
#include <functional>
#include <iostream>
#include "Ecuacion.h"

class Defensa {
private: 
	bool esquiva(ObjetoJuego &atacado);

public: 
	Defensa();

	float getDanioConDefensa(ObjetoJuego &atacado, float danio);

	~Defensa();
};

#endif
