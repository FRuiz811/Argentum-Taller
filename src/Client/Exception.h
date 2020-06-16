#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <typeinfo>
#define BUFF_SIZE 256

class Exception : public std::exception {
private: 
	char msg_error[BUFF_SIZE];
public:
	explicit Exception(const char* msg, ...) noexcept;

	virtual const char* what() const noexcept;

	virtual ~Exception() noexcept;
};

#endif
