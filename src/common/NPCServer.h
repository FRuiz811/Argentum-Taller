#ifndef NPC_H
#define NPC_H

#include "GameObject.h"

class NPCServer : public GameObject{
private:
    //TODO agregar items que puedan tener ( unorded_map<Id, Precio>)
public:
	explicit NPCServer(uint id, Point point, std::string type);

    void update() override;

	virtual ~NPCServer();
};

#endif
