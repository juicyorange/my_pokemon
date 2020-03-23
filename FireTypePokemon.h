#pragma once
#include "Pokemon.h"
class FireTypePokemon :
	public Pokemon
{
public:
	FireTypePokemon() {
		type = FIRE;
	};
	~FireTypePokemon();
};

