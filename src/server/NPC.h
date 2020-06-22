#ifndef NPC_H
#define NPC_H

#include "Position.h"
#include "GameObject.h"

class NPC : public GameObject{
	//Pocion de vida, mana, oro, otro obj al azar
private: 

public: 
	NPC();

	Position getPosicion(){}
	/*Constructor del NPC.*/

	~NPC();
	/*Destructor del NPC.*/
};

#endif
