#include "pokemon.h"
#include <ctime>


Pokemon::Pokemon()
{
}


Pokemon::~Pokemon()
{
}


void Pokemon::set_name(string name)
{
	this->name = name;
}
string Pokemon::get_name()
{
	return name;
}

void Pokemon::set_HP(int HP)
{
	this->HP = HP;
	if(this->HP > Max_hp)
		this->HP = Max_hp;
}
int Pokemon::get_HP()
{
	return HP;
}

void Pokemon::set_type(Type type)
{
	this->type = type;
}
Type Pokemon::get_type()
{
	return type;
}

void Pokemon::set_exp(int exp)
{
	this->exp = exp;
	while (this->exp > 100)
	{
		level_up();
		this->exp -= 100;
	}
}
int Pokemon::get_exp()
{
	return exp;
}

void Pokemon::set_level(int level)
{
	this->level = level;
}
int Pokemon::get_level()
{
	return level;
}

int Pokemon::get_sell_money()
{
	return sell_money;
}

void Pokemon::level_up()
{
	level++;
	int num;
	srand(time(NULL));
	num = rand() % 3 + 2;
	Max_hp += num;
	HP = Max_hp;
	is_evolve = false;
}

bool Pokemon::evolve()
{
	if (is_evolve == false && (level == 15 || level == 30)) {
		is_evolve = true;
		return true;
	}
	return false;
}

Skill * Pokemon::get_skill_list()
{
	return skill_list;
}

int Pokemon::get_skill_count()
{
	return skill_idx + 1;
}

bool Pokemon::damaged(int damage, Type o_type)
{
	if (type == FIRE)
	{
		if (o_type == WATER)
		{
			damage = damage*1.3;
		}
		else if(o_type == GRASS)
		{
			damage = damage*0.7;
		}
	}
	else if (type == WATER)
	{
		if (o_type == GRASS)
		{
			damage = damage*1.3;
		}
		else if (o_type == FIRE)
		{
			damage = damage*0.7;
		}
	}
	else if (type == GRASS)
	{
		if (o_type == FIRE)
		{
			damage = damage*1.3;
		}
		else if (o_type == WATER)
		{
			damage = damage*0.7;
		}
	}
	HP -= damage;

	if (HP <= 0)
	{
		HP = 0;
		return true;
	}
	return false;
}
