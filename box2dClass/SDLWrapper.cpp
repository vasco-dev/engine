#include "SDLWrapper.h"
#include "InitError.h"

SDLWrapper::SDLWrapper(Uint32 flags /*= 0*/) throw(InitError)
{
	if (SDL_Init(flags) != 0)
		throw InitError();
}

SDLWrapper::~SDLWrapper()
{
	SDL_Quit();
}
