#ifndef POSICION_H
#define POSICION_H

class Posicion {
private: 
	int coordenadaX;
	int coordenadaY;
public: 
	Posicion(int coordenadaX, int coordenadaY);
	//Posicion getPosicion();
	int getCoordenadaX();
	int getCoordenadaY();
	~Posicion();
};

#endif
