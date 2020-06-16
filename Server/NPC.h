#ifndef NPC_H
#define NPC_H

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
