#include "User.h"
#include "Monsterball.h"
#include <ctime>
User::User() {
	name = "null";
	money = 10000;
	heal = 5;
	base_ball = 5;
	super_ball = 3;
	master_ball = 1;
	for (int i = 0; i < 6; i++)
	{
		pokemonArr[i] = nullptr;
	}
};


User::~User()
{
	for (int i = 0; i < 6; i++)
	{
		if (pokemonArr[i] != nullptr)
			delete pokemonArr[i];
	}
}

int User::get_heal_cnt()
{
	return heal;
}

bool User::use_heal()
{
	if (heal <= 0)
		return false;
	
	heal--;
	return true;
}

int User::get_base_ball()
{
	return base_ball;
}

void User::set_base_ball(int num)
{
	this->base_ball = num;
}

int User::get_super_ball()
{
	return super_ball;
}

void User::set_super_ball(int num)
{
	this->super_ball = num;
}

int User::get_master_ball()
{
	return master_ball;
}

void User::set_master_ball(int num)
{
	this->master_ball = num;
}


bool User::gain_pokemon(Pokemon* pokomon)
{
	if (pokemonIdx < 6)
	{
		pokemonArr[pokemonIdx] = new Pokemon(*pokomon);
		pokemonIdx++;
		return true;
	}
	return false;
}

void User::set_pokemon(Pokemon* pokemon, int num)
{
	pokemonArr[num] = new Pokemon(*pokemon);
}

void User::set_pokemonIdx(int idx)
{
	this->pokemonIdx = idx;
}

bool User::catch_monster(Pokemon *fight_mon, int monsterball_type)
{
	if (pokemonIdx > 6)
		return false;

	if (monsterball_type == 1)
	{
		if (base_ball > 0)
		{
			base_ball--;
			Baseball base;
			if (base.catch_mon())
			{
				return gain_pokemon(fight_mon);
			}
			return false;
		}
		else
			cout << "몬스터볼이 부족합니다" << endl;
	}
	else if (monsterball_type == 2)
	{
		if (super_ball > 0)
		{
			super_ball--;
			Superball super;
			if (super.catch_mon())
			{
				return gain_pokemon(fight_mon);
			}
			return false;
		}
		else
			cout << "슈퍼볼이 부족합니다" << endl;
	}
	else if(monsterball_type==3)
	{
		if (master_ball > 0)
		{
			master_ball--;
			Masterball master;
			if (master.catch_mon())
			{
				return gain_pokemon(fight_mon);
			}
			return false;
		}
		else
			cout << "마스터볼이 부족합니다" << endl;
	}

}

int User::get_heal()
{
	return heal;
}
void User::set_heal(int num)
{
	this->heal = num;
}