#include "Arma.h"

Arma::Arma() : aDistancia(false), danioMin(0.1), danioMax(0.1){}

bool Arma::esArmaDistancia(){
	return aDistancia;
}

float Arma::getDanioMin(){
	return danioMin;
}
float Arma::getDanioMax(){
	return danioMax;
}

Arma::~Arma(){}