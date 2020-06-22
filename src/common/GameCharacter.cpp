#include "GameCharacter.h"

GameCharacter::GameCharacter(int race, int gameClass, Position posicion) :
GameObject(std::move(posicion)), race(race), gameClass(gameClass) {

}

GameCharacter::GameCharacter(GameCharacter &&other) noexcept : GameObject(std::move(other)) {
    std::swap(race, other.race);
    std::swap(gameClass, other.gameClass);
    std::swap(position, other.position);
}

GameCharacter &GameCharacter::operator=(GameCharacter &&other) noexcept {
   if (&other == this) {
       return *this;
   }
    std::swap(race, other.race);
    std::swap(gameClass, other.gameClass);
    std::swap(position, other.position);
    return *this;
}

GameCharacter::GameCharacter() = default;

//void GameCharacter::corroborarAtaque(GameObject &atacado){
//	if(!arma.esArmaDistancia() &&
//		(abs(getCoordenadaX() - atacado.getCoordenadaX()) > 1 ||
//		abs(getCoordenadaY() - atacado.getCoordenadaY()) > 1)) {
//		throw AtaqueInvalido();
//	}
//	if(abs(this->estado.getNivel() - atacado.estado.getNivel()) > 10) { //ToDO: poner en estados
//		throw AtaqueNivelInvalido();
//	}
//}

//void GameCharacter::atacar(GameObject &atacado){
//	corroborarAtaque(atacado);
//	float experiencia = ataque.atacar(atacado, arma, this->estado.getNivel());
//	this->estado.updateNivel(experiencia);
//}
//
//void GameCharacter::equiparArma(Arma arma){
//	this->arma = arma;
//}
	

GameCharacter::~GameCharacter()= default;

