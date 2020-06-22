#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "GameObject.h"

class GameCharacter : public GameObject{
private:
    int race{};
    int gameClass{};
	//Inventario inventario;

//	Arma arma;
//	Ataque ataque;
//	void corroborarAtaque(GameObject &atacado);
	
public: 
	//Arma armadura;
	//Arma escudo;
	//Arma casco;

	//ToDo: separar armadura-escudo-casco
    GameCharacter();
	GameCharacter(int raza, int clase, Position posicion);
	GameCharacter(GameCharacter&& other) noexcept;
	GameCharacter& operator=(GameCharacter&& other) noexcept;
//	void equiparArma(Arma arma);
//
//	void atacar(GameObject &atacado);

	~GameCharacter();
};

#endif
