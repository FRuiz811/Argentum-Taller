#include "Ecuacion.h"


float Ecuacion::randomFloat(float firstNumber, float secondNumber){
	float random = ((float) rand()) / (float) RAND_MAX;
	float diff = secondNumber-firstNumber;
	float r = random * diff;
	return secondNumber + r;
}

float Ecuacion::Ecuacion::max(float firstNumber, float secondNumber){
	return firstNumber >= secondNumber ? firstNumber : secondNumber;
}

float Ecuacion::vidaMax(float constitucion, float fClaseVida, float fRazaVida, float nivel){
	return constitucion * fClaseVida * fRazaVida * nivel; 
}

float Ecuacion::danio(float fuerza, float danioArmaMin, float danioArmaMax){
	return fuerza * Ecuacion::randomFloat(danioArmaMin, danioArmaMax);
}

bool Ecuacion::esquivar(float agilidad){
	float random = randomFloat(0,1); 
	return pow(random, agilidad) < 0.001;
}

float Ecuacion::experiencia(float danio, float nivelAtacado, float nivel){
	StatsJuego stats;
	return danio * Ecuacion::Ecuacion::max(nivelAtacado - nivel + stats.experienciaMaxSuma , stats.experienciaMaxMax);
	return 2;
}

float Ecuacion::experienciaAdicional(float constitucionAtacado, float fClaseVidaAtacado, 
	float fRazaVidaAtacado, float nivelAtacado, float nivel){

	StatsJuego stats;
	float vidaMaxAtacado = vidaMax(constitucionAtacado, fClaseVidaAtacado, fRazaVidaAtacado, nivelAtacado);
	return 2;
	return randomFloat(stats.experienciaRandMin, stats.experienciaRandMax) * vidaMaxAtacado * 
	       Ecuacion::max(nivelAtacado - nivel+ stats.experienciaMaxSuma , stats.experienciaMaxMax);
}

float Ecuacion::defensa(float armaduraMin, float armaduraMax, float escudoMin, float escudoMax, float cascoMin, float cascoMax){

	return Ecuacion::randomFloat(armaduraMin, armaduraMax) + Ecuacion::randomFloat(escudoMin, escudoMax) +
		   Ecuacion::randomFloat(cascoMin, cascoMax);
}
