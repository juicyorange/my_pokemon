#pragma once
#include <string>
#include "pokemon.h"
#include "Monsterball.h"
#include "Superball.h"
#include "Baseball.h"
#include "Masterball.h"
using namespace std;

class User
{
public:
	User();
	~User();

private:
	string name;
	int money;
	Pokemon* pokemonArr[6];
	int pokemonIdx = 0;
	int heal;
	int base_ball;
	int super_ball;
	int master_ball;

public:
	int get_money() {
		return money;
	}
	int get_heal_cnt();
	bool use_heal();

	string get_name() {
		return name;
	}

	int get_base_ball();
	void set_base_ball(int num);

	int get_super_ball();
	void set_super_ball(int num);

	int get_master_ball();
	void set_master_ball(int num);


	void set_name(string user_name)
	{
		this->name = user_name;
	}

	void set_money(int money)
	{
		this->money = money;
	}

	bool gain_pokemon(Pokemon* pokomon);

	void set_pokemon(Pokemon * pokemon, int num);

	Pokemon** get_pokemon_list()
	{
		return pokemonArr;
	}

	void del_pokemon_list(int i)
	{
		delete pokemonArr[i];
		pokemonArr[i] = nullptr;
		for (; i < pokemonIdx-1;i++)
		{
			pokemonArr[i] = pokemonArr[i + 1];
			pokemonArr[i + 1] = nullptr;
		}
		pokemonIdx--;
	}

	int get_pokemon_size()
	{
		return pokemonIdx;
	}

	void set_pokemonIdx(int idx);

	bool catch_monster(Pokemon *fight_mon, int monsterball_type);

	int get_heal();
	void set_heal(int num);
};

