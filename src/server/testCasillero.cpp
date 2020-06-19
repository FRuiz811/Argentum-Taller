#include "StatsJuego.h"
#include <iostream>
#include "Casillero.h"

void test01CasilleroVacio();
void test02CasilleroNoVacio();
void test03ObtenerObjetoDelCasillero();
void test04EliminarObjetoDeCasillero();
void test05ObtenerObjetoCasilleroVacio();
void test06EliminarObjetoCasilleroVacio();

int main(int argc, char*argv[]){
	try{
		//StatsJuego stats;	
		//std::cout << stats.oroRandMax << '\n';

		//Personaje personaje(Humano());
		//personaje.getRaza();
		test01CasilleroVacio();
		test02CasilleroNoVacio();
		test03ObtenerObjetoDelCasillero();
		test04EliminarObjetoDeCasillero();
		test05ObtenerObjetoCasilleroVacio();
		test06EliminarObjetoCasilleroVacio();

		return 0;
	} catch(std::exception& e){
		std::cout << "EXCEPCION: \n"<<e.what();
		return 1;
	}
}


void test01CasilleroVacio(){
	Casillero casiller;
	if(casiller.estaVacio()){
		std::cout << "OK 01" << '\n';
	}
	else std::cout << "MAL 01" << '\n';
}

void test02CasilleroNoVacio(){
	Casillero casillero;
	ObjetoJuego objeto;
	//casillero.agregarObjeto(std::move(objeto));
	casillero.agregarObjeto(&objeto);


	if(!casillero.estaVacio()){
		std::cout << "OK 02" << '\n';
	}
	else std::cout << "MAL 02" << '\n';
}

void test03ObtenerObjetoDelCasillero(){
	Casillero casillero;
	ObjetoJuego objeto;
	//casillero.agregarObjeto(std::move(objeto));
	casillero.agregarObjeto(&objeto);

	if(&objeto == casillero.obtenerObjeto()){
		std::cout << "OK 03" << '\n';
	}
	else {
		std::cout << "MAL 03" << '\n';
	}
}

void test04EliminarObjetoDeCasillero(){
	Casillero casillero;
	ObjetoJuego objeto;

	casillero.agregarObjeto(&objeto);
	ObjetoJuego* objetoEliminado = casillero.eliminarObjeto();


	if(&objeto == objetoEliminado){
		std::cout << "OK 04" << '\n';
	}
	else {
		std::cout << "MAL 04" << '\n';
	}

	if(casillero.estaVacio()){
		std::cout << "OK 04" << '\n';
	}
	else std::cout << "MAL 04" << '\n';
}

void test05ObtenerObjetoCasilleroVacio(){
	try{
		Casillero casillero;
		casillero.obtenerObjeto();
	}catch(CasilleroVacio e){
		std::cout << "OK 05" << '\n';
	}
}


void test06EliminarObjetoCasilleroVacio(){
	try{
		Casillero casillero;
		casillero.eliminarObjeto();
	}catch(CasilleroVacio e){
		std::cout << "OK 06" << '\n';
	}
}