#ifndef INITERROR
#define INITERROR

#include <exception>
#include <string>
#include <sdl2/SDL.h>

class InitError : std::exception {
	public:
		InitError();
		InitError(const std::string&);
		virtual ~InitError() throw();
		virtual const char* what() const throw();
	private:
		std::string msg;
};

#endif