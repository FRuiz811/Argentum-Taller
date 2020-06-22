#include <iostream>
#include "StatsJuego.h"

void test01CrearPersonacompararPosicion();
void test02CrearPersonacompararConstitucion();
void test03CrearPersonacompararInteligencia();
void test04CrearPersonacompararAgilidad();
void test05CrearPersonaConPosicionRazaClase();
void test06CrearDosPersonasInicialmenteYAtacarlos();
void test07CrearUnaPersonaYUnaCriaturaInicialmenteYAtacarlos();
void test08CrearUnaPersonaYUnaCriaturaYMatarlo();


//int main(int argc, char*argv[]){
//	try{
		
//		test01CrearPersonacompararPosicion();
//		test02CrearPersonacompararConstitucion();
//		test03CrearPersonacompararInteligencia();
//		test04CrearPersonacompararAgilidad();
//		test05CrearPersonaConPosicionRazaClase();
//		test06CrearDosPersonasInicialmenteYAtacarlos();
//		test07CrearUnaPersonaYUnaCriaturaInicialmenteYAtacarlos();
//		test08CrearUnaPersonaYUnaCriaturaYMatarlo();
//
//		return 0;
//	} catch(std::exception& e){
//		std::cout << "EXCEPCION: \n"<<e.what();
//		return 1;
//	}
//}

//void test01CrearPersonacompararPosicion(){
//	int humano = 0;
//	int mago = 0;
//	Position posicion(1, 1);
//	GameCharacter personaje(humano, mago, posicion);
//	int x = personaje.getCoordenadaX();
//	int y = personaje.getCoordenadaY();
//
//	if(x == posicion.getCoordenadaX() && y == posicion.getCoordenadaY() ){
//		std::cout << "OK 01" << '\n';
//	}
//	else {
//		std::cout << "MAL 01" << '\n';
//
//	}
//
//}


//void test02CrearPersonacompararConstitucion(){
//	int humano = 0;
//	int mago = 0;
//	Position posicion(1, 1);
//	GameCharacter personaje(humano, mago, posicion);
//
//	float constitucion = (1+0.8)/2;
//	float epsilon = 0.01f;
//	if(fabs(personaje.estado.getConstitucion() - constitucion) <= epsilon){
//		std::cout << "OK 02" << '\n';
//	}
//	else {
//		std::cout << "MAL 02" << '\n';
//	}
//}
//
//void test03CrearPersonacompararInteligencia(){
//	int humano = 0;
//	int mago = 0;
//	Position posicion(1, 1);
//	GameCharacter personaje(humano, mago, posicion);
//
//	float inteligencia = (1+1.8)/2;
//
//	float epsilon = 0.01f;
//	if(fabs(personaje.estado.getInteligencia() - inteligencia) <= epsilon){
//		std::cout << "OK 03" << '\n';
//	}
//	else {
//		std::cout << "MAL 3" << '\n';
//
//	}
//
//}
//
//
//void test04CrearPersonacompararAgilidad(){
//	int humano = 0;
//	int mago = 0;
//	Position posicion(1, 1);
//	GameCharacter personaje(humano, mago, posicion);
//
//	float agilidad = (1+0.4)/2;
//	float epsilon = 0.01f;
//	if(fabs(personaje.estado.getAgilidad() - agilidad) <= epsilon ){
//		std::cout << "OK 04" << '\n';
//	}
//	else {
//		std::cout << "MAL 04" << '\n';
//	}
//
//}
//
//void test05CrearPersonaConPosicionRazaClase(){
//	int humano = 0;
//	int mago = 0;
//	Position posicion(1, 1);
//	GameCharacter personaje(humano, mago, posicion);
//	int x = personaje.getCoordenadaX();
//	int y = personaje.getCoordenadaY();
//
//	float constitucion = (1+0.8)/2;
//	float inteligencia = (1+1.8)/2;
//	float agilidad = (1+0.4)/2;
//	float epsilon = 0.01f;
//	if(x == posicion.getCoordenadaX() && y == posicion.getCoordenadaY() &&
//		fabs(personaje.estado.getConstitucion() - constitucion) <= epsilon &&
//		fabs(personaje.estado.getInteligencia() - inteligencia) <= epsilon &&
//		fabs(personaje.estado.getAgilidad() - agilidad) <= epsilon ){
//		std::cout << "OK 05" << '\n';
//	}
//	else {
//		std::cout << "MAL 05" << '\n';
//		std::cout << "estado const" << personaje.estado.getConstitucion() << " no " << constitucion << '\n';
//		std::cout << "estado " << personaje.estado.getInteligencia() << " no " << ((1+1.8)/2) << '\n';
//		std::cout << "estado " << personaje.estado.getAgilidad() << " no " << ((1+0.4)/2) << '\n';
//	}
//}
//
//void test06CrearDosPersonasInicialmenteYAtacarlos(){
//	try{
//		int humano = 0;
//		int mago = 0;
//		Position posicion(1, 1);
//		GameCharacter personaje(humano, mago, posicion);
//		Position posicionAtacado(1, 2);
//		GameCharacter personajeAtacado(humano, mago, posicionAtacado);
//
//		float vidaInicial =  personajeAtacado.estado.getVida();
//		personaje.atacar(personajeAtacado);
//
//		float vidaFinal = personajeAtacado.estado.getVida();
//		if(vidaFinal <= vidaInicial){
//			std::cout << "OK 06: "<< '\n';
//			std::cout << "\tvida inicial " << vidaInicial << " final " << vidaFinal << '\n';
//		}
//
//	} catch(AtaqueInvalido ai){
//		std::cout << "MAL 06 ataque invalido" << '\n';
//
//	}catch(AtaqueNivelInvalido ni){
//		std::cout << "MAL 06 ataque invalido" << '\n';
//	}
//}
//
//void test07CrearUnaPersonaYUnaCriaturaInicialmenteYAtacarlos(){
//	try{
//
//		Position posicion(1, 1);
//		GameCharacter personaje(1, 3, posicion);
//		Position posicionAtacado(1, 2);
//		Criatura criatura(posicionAtacado);
//
//		float vidaInicial =  criatura.estado.getVida();
//		personaje.atacar(criatura);
//
//		float vidaFinal = criatura.estado.getVida();
//		if(vidaFinal <= vidaInicial){
//			std::cout << "OK 07: "<< '\n';
//			std::cout << "\tvida inicial " << vidaInicial << " final " << vidaFinal << '\n';
//		}
//
//	} catch(AtaqueInvalido ai){
//		std::cout << "MAL 07 ataque invalido" << '\n';
//
//	}catch(AtaqueNivelInvalido ni){
//		std::cout << "MAL 07 ataque invalido" << '\n';
//	}
//}
//
//void test08CrearUnaPersonaYUnaCriaturaYMatarlo(){
//	try{
//		Position posicion(1, 1);
//		GameCharacter personaje(1, 3, posicion);
//		Position posicionAtacado(1, 2);
//		Criatura criatura(posicionAtacado);
//
//		float vidaInicial =  criatura.estado.getVida();
//		personaje.atacar(criatura);
//
//		while(criatura.estado.sigueVivo()){
//			personaje.atacar(criatura);
//		}
//		std::cout << "OK 08: "<< '\n';
//		std::cout << "\tvida inicial " << vidaInicial << " final " << criatura.estado.getVida() << '\n';
//	} catch(AtaqueInvalido ai){
//		std::cout << "MAL 08 ataque invalido" << '\n';
//
//	}catch(AtaqueNivelInvalido ni){
//		std::cout << "MAL 08 ataque invalido" << '\n';
//	}
//}
