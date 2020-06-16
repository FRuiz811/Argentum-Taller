#include "Personaje.h"

Personaje::Personaje(int raza, int clase, Posicion posicion) : ObjetoJuego(raza,clase, posicion){}

void Personaje::corroborarAtaque(ObjetoJuego &atacado){
	if(!arma.esArmaDistancia() && 
		(abs(getCoordenadaX() - atacado.getCoordenadaX()) > 1 ||
		abs(getCoordenadaY() - atacado.getCoordenadaY()) > 1)) {
		throw AtaqueInvalido();
	}
	if(abs(this->estado.getNivel() - atacado.estado.getNivel()) > 10){ //ToDO: poner en estados
		throw AtaqueNivelInvalido();
	}
}

void Personaje::atacar(ObjetoJuego &atacado){
	corroborarAtaque(atacado);
	float experiencia = ataque.atacar(atacado, arma, this->estado.getNivel());
	this->estado.updateNivel(experiencia);
}

void Personaje::equiparArma(Arma arma){
	this->arma = arma;
}
	

Personaje::~Personaje(){}
