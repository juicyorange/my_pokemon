#pragma once
#include "Pokemon.h"
class GrassTypePokemon :
	public Pokemon
{
public:
	GrassTypePokemon() {
		type = GRASS;
	};
	~GrassTypePokemon();
};

