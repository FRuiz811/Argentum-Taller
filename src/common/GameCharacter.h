#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "GameObject.h"
#include "EventQueue.h"

class GameCharacter : public GameObject{
private:
    int race{};
    int gameClass{};
    EventQueue eventQueue;
	//Inventario inventario;

//	Arma arma;
//	Ataque ataque;
//	void corroborarAtaque(GameObject &atacado);
	
public:
    GameCharacter();
	GameCharacter(int raza, int clase, Position posicion);

	GameCharacter(GameCharacter&& other) noexcept;
	GameCharacter& operator=(GameCharacter&& other) noexcept;

    void update() override;

    ~GameCharacter();
};

#endif
