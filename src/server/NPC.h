#ifndef NPC_H
#define NPC_H

#include "Posicion.h"
#include "ObjetoJuego.h"

class NPC : public ObjetoJuego{
	//Pocion de vida, mana, oro, otro obj al azar
private: 

public: 
	NPC();

	Posicion getPosicion(){}
	/*Constructor del NPC.*/

	~NPC();
	/*Destructor del NPC.*/
};

#endif
