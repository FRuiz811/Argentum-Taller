#include "StatsJuego.h"
#include <iostream>
#include "Cell.h"

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

		//Character personaje(Humano());
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
	Cell casiller;
	if(casiller.estaVacio()){
		std::cout << "OK 01" << '\n';
	}
	else std::cout << "MAL 01" << '\n';
}

void test02CasilleroNoVacio(){
	Cell casillero;
	GameObject objeto;
	//casillero.agregarObjeto(std::move(objeto));
	casillero.agregarObjeto(&objeto);


	if(!casillero.estaVacio()){
		std::cout << "OK 02" << '\n';
	}
	else std::cout << "MAL 02" << '\n';
}

void test03ObtenerObjetoDelCasillero(){
	Cell casillero;
	GameObject objeto;
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
	Cell casillero;
	GameObject objeto;

	casillero.agregarObjeto(&objeto);
	GameObject* objetoEliminado = casillero.eliminarObjeto();


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
		Cell casillero;
		casillero.obtenerObjeto();
	}catch(CasilleroVacio e){
		std::cout << "OK 05" << '\n';
	}
}


void test06EliminarObjetoCasilleroVacio(){
	try{
		Cell casillero;
		casillero.eliminarObjeto();
	}catch(CasilleroVacio e){
		std::cout << "OK 06" << '\n';
	}
}