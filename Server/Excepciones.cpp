#include "Excepciones.h"

const char* CasilleroOcupado::what() const throw(){
	return "Error: El casillero está ocupado.\n";
}

const char* CasilleroVacio::what() const throw(){
	return "Error: El casillero está vacio.\n";
}

const char* AtaqueInvalido::what() const throw(){
	return "Error: El ataque es inválido.\n";
}

const char* AtaqueNivelInvalido::what() const throw(){
	return "Error: El ataque es inválido debido a que la diferencia de niveles es mayor a diez.\n";
}