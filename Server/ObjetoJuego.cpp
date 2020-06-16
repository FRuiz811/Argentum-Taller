#include "ObjetoJuego.h"

//ObjetoJuego::ObjetoJuego() : movimiento(Movimiento(Posicion(-1,-1))),  estado(Estado(0, 0)){}
//	Posicion pos(-1,-1);
//	Movimiento mov(pos);
//	movimiento = mov;
//	Estado est(0,0);
//	estado = est;
//}
ObjetoJuego::ObjetoJuego(Posicion posicion) : movimiento(Movimiento(posicion)), estado(Estado()) {}

ObjetoJuego::ObjetoJuego(int raza, int clase, Posicion posicion) : movimiento(Movimiento(posicion)),  estado(Estado(raza, clase)){}


ObjetoJuego::ObjetoJuego(ObjetoJuego&& other) {
}


ObjetoJuego& ObjetoJuego::operator=(ObjetoJuego&& other){
	return *this;
}

int ObjetoJuego::getCoordenadaX(){
	return this->movimiento.getCoordenadaX();
}
int ObjetoJuego::getCoordenadaY(){
	return this->movimiento.getCoordenadaY();
}

ObjetoJuego::~ObjetoJuego(){}