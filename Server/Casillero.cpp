#include "Casillero.h"

Casillero::Casillero() : vacio(true){}
	
void Casillero::agregarObjeto(ObjetoJuego* unObjeto){
	if(!estaVacio()){
		throw CasilleroOcupado();
	}
	this->objeto = unObjeto;
	this->vacio = false;
}

ObjetoJuego* Casillero::eliminarObjeto(){
	if(estaVacio()){
		throw CasilleroVacio();
	}
	this->vacio = true;
	return this->objeto;
}

ObjetoJuego* Casillero::obtenerObjeto(){
	if(estaVacio()){
		throw CasilleroVacio();
	}
	//ObjetoJuego unObjeto = this->objeto;
	//this->objeto = NULL;
	
	return this->objeto;
}

bool Casillero::estaVacio(){
	return vacio;
}

Casillero::~Casillero(){}