#ifndef SDLEXCEPTION_H
#define SDLEXCEPTION_H

#include <typeinfo>
#define BUFF_SIZE 256

class SDLException : public std::exception {
private: 
	char msg_error[BUFF_SIZE];
public:
	explicit SDLException(const char* msg, ...) noexcept;

	virtual const char* what() const noexcept;

	virtual ~SDLException() noexcept;
};

#endif
