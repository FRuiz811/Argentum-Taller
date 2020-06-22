#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "GameObject.h"

class Character : public GameObject{
private:
    int race;
    int gameClass;
	//Inventario inventario;

//	Arma arma;
//	Ataque ataque;
//	void corroborarAtaque(GameObject &atacado);
	
public: 
	//Arma armadura;
	//Arma escudo;
	//Arma casco;

	//ToDo: separar armadura-escudo-casco
    Character();
	Character(int raza, int clase, Position posicion);
	bool move(int);
//	void equiparArma(Arma arma);
//
//	void atacar(GameObject &atacado);

	~Character();
	/*Destructor del Character.*/

private: 
	//bool esAtacable();
};

#endif
