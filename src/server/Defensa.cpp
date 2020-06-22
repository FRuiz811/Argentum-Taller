#include "Defensa.h"

Defensa::Defensa(){}

bool Defensa::esquiva(GameObject &atacado){
	return Ecuacion::esquivar(atacado.estado.getAgilidad());
}

float Defensa::getDanioConDefensa(GameObject &atacado, float danio){
	if(esquiva(atacado)) return 0;

	// armaduraMin = atacado.armadura.getDanioMin(;
	// armaduraMax = atacado.armadura.getDanioMax(;
	// escudoMin = atacado.escudo.getDanioMin();
	// escudoMax = atacado.escudo.getDanioMax();
	// cascoMin = atacado.casco.getDanioMin();
	// cascoMax = atacado.casco.getDanioMax();

	float armaduraMin = 0;
	float armaduraMax = 0;
	float escudoMin = 0;
	float escudoMax = 0;
	float cascoMin = 0;
	float cascoMax = 0;

	float defensa = Ecuacion::defensa(armaduraMin, armaduraMax, escudoMin, escudoMax, cascoMin, cascoMax);
	float total = defensa > danio ? 0 : danio - defensa;
	return total;
}

Defensa::~Defensa(){}

