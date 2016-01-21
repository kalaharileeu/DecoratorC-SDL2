#pragma once
#include <iostream>
#include "SDL.h"

static int Getsometicks()
{
	int ticks = SDL_GetTicks() % 100;
	return ticks;
}