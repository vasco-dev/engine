#pragma once
#include <sdl2/SDL.h>
#include "InitError.h"

class SDLWrapper
{
public:
	SDLWrapper(Uint32 flags = 0) throw(InitError);

	virtual ~SDLWrapper();
};

