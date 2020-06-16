#ifndef ECUACION_H
#define ECUACION_H
#include <cstdlib>
#include <math.h>
#include "StatsJuego.h"
#include <algorithm>

class Ecuacion{
private: 
	static float randomFloat(float firstNumber, float secondNumber);
public: 
	static float vidaMax(float constitucion, float fClasaVida, float fRazaVida, float nivel);
	
	static float danio(float fuerza, float danioArmaMin, float danioArmaMax);

	static float experiencia(float danio, float nivelAtacado, float nivel);

	static float experienciaAdicional(float constitucionAtacado, float fClaseVidaAtacado, 
	float fRazaVidaAtacado, float nivelAtacado, float nivel);

	static bool esquivar(float agilidad);

	static float max(float firstNumber, float secondNumber);

	static float defensa(float armaduraMin, float armaduraMax, float escudoMin, float escudoMax, float cascoMin, float cascoMax);
};

#endif
