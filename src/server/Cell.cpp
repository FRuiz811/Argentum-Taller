#include "Cell.h"

Cell::Cell() : vacio(true){}
	
void Cell::agregarObjeto(GameObject* unObjeto){
	if(!estaVacio()){
		throw CasilleroOcupado();
	}
	this->objeto = unObjeto;
	this->vacio = false;
}

GameObject* Cell::eliminarObjeto(){
	if(estaVacio()){
		throw CasilleroVacio();
	}
	this->vacio = true;
	return this->objeto;
}

GameObject* Cell::obtenerObjeto(){
	if(estaVacio()){
		throw CasilleroVacio();
	}
	//GameObject unObjeto = this->objeto;
	//this->objeto = NULL;
	
	return this->objeto;
}

bool Cell::estaVacio(){
	return vacio;
}

Cell::~Cell(){}