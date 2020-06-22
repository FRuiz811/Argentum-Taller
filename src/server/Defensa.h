#ifndef DEFENSA_H
#define DEFENSA_H
#include "GameObject.h"
#include "Excepciones.h"
#include <functional>
#include <iostream>
#include "Ecuacion.h"

class Defensa {
private: 
	bool esquiva(GameObject &atacado);

public: 
	Defensa();

	float getDanioConDefensa(GameObject &atacado, float danio);

	~Defensa();
};

#endif
