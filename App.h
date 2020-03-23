#pragma once
#include "User.h"
#include "Charmander.h"
#include "Bulbasaur.h"
#include "Squirtle.h"
#include "Charmeleon.h"
#include <string>
#include <iostream>
#include "Skill.h"
#include "Ivysaur.h"
#include "Blastoise.h"
#include "Charizard.h"
#include "Venusaur.h"
#include "Wartortle.h"
#include "legend.h"

using namespace std;
class App
{
public:
	App();
	~App();

	void run();

private:
	User* user;
private:
	void start_game();
	void print_menu();
	void fight();
	void check_pokemon();
	void sell_pokemon();
	void all_heal();
	void shop();
	void evolve_mon(Pokemon *my_mon);
	
};

