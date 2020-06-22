#include "Estado.h"

Estado::Estado() : nivel(0),raza(Raza(0)), clase(Clase(0)){
	obtenerEstadosCriaturas();
}

Estado::Estado(int numRaza, int numClase) : nivel(1), raza(Raza(numRaza)), clase(Clase(numClase)) {
	obtenerEstados(numRaza, numClase);
}

void Estado::obtenerEstados(int numRaza, int numClase){
	StatsJuego stats;	
 //ToDO: Ver si no conviene dejar la const, int y llamar con el int en las ecuaciones
	this->constitucion = (stats.constitucionRaza[numRaza] + stats.constitucionClase[numClase]) / 2;
	this->inteligencia = (stats.inteligenciaRaza[numRaza] + stats.inteligenciaClase[numClase]) / 2;
	this->agilidad = (stats.agilidadRaza[numRaza] + stats.agilidadClase[numClase]) / 2;

	this->vida = Ecuacion::vidaMax(constitucion, clase.fVida,  raza.fVida, nivel);
	this->fuerza = stats.fuerza;//ToDo: ver que todos empiezan con la misma fuerza;
}

void Estado::obtenerEstadosCriaturas(){
	StatsJuego stats;	
 //ToDO: Ver si no conviene dejar la const, int y llamar con el int en las ecuaciones
	this->constitucion = stats.datosCriatura;
	this->inteligencia = stats.datosCriatura;
	this->agilidad = stats.datosCriatura;
	this->vida = stats.vidaCriatura;
	this->fuerza = stats.fuerzaCriatura;
}

float Estado::getAgilidad(){
	return this->agilidad;
}
float Estado::getConstitucion(){
	return this->constitucion;
}
float Estado::getInteligencia(){
	return this->inteligencia;
}

int Estado::getNivel(){
	return this->nivel;
}
float Estado::getVida(){
	return this->vida;
}

float Estado::getFClaseVida(){
	return this->clase.fVida;
}
float Estado::getFRazaVida(){
	return this->raza.fVida;
}

void Estado::restarVida(float danio){
	this->vida -= danio; 
}

bool Estado::sigueVivo(){
	return this->vida > 0;
}

void Estado::setearAMuerto(){
	this->constitucion = 0;
	this->inteligencia = 0;
	this->agilidad = 0;
	this->vida = 0;
	this->fuerza = 0;
}

void Estado::updateNivel(float experiencia){
	this->nivel +=experiencia;
}
Estado::~Estado(){}