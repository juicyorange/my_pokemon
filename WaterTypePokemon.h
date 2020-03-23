#pragma once
#include "Pokemon.h"
class WaterTypePokemon :
	public Pokemon
{
public:
	WaterTypePokemon() {
		type = WATER;
	};
	~WaterTypePokemon();
};

