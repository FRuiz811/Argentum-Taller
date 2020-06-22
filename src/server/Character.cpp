#include "Character.h"

Character::Character(int race, int gameClass, Position posicion) :
GameObject(std::move(posicion)), race(race), gameClass(gameClass) {

}

bool Character::move(int) {

}

Character::Character() = default;

//void Character::corroborarAtaque(GameObject &atacado){
//	if(!arma.esArmaDistancia() &&
//		(abs(getCoordenadaX() - atacado.getCoordenadaX()) > 1 ||
//		abs(getCoordenadaY() - atacado.getCoordenadaY()) > 1)) {
//		throw AtaqueInvalido();
//	}
//	if(abs(this->estado.getNivel() - atacado.estado.getNivel()) > 10) { //ToDO: poner en estados
//		throw AtaqueNivelInvalido();
//	}
//}

//void Character::atacar(GameObject &atacado){
//	corroborarAtaque(atacado);
//	float experiencia = ataque.atacar(atacado, arma, this->estado.getNivel());
//	this->estado.updateNivel(experiencia);
//}
//
//void Character::equiparArma(Arma arma){
//	this->arma = arma;
//}
	

Character::~Character()= default;

