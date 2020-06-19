#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <stdio.h>
#include <exception>

class CasilleroOcupado: public std::exception{
public:
	const char* what() const throw();
};

class CasilleroVacio: public std::exception{
public:
	const char* what() const throw();
};

class AtaqueInvalido: public std::exception{
public:
	const char* what() const throw();
};

class AtaqueNivelInvalido: public std::exception{
public:
	const char* what() const throw();
};




#endif
