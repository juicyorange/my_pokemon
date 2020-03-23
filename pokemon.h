#pragma once

#include <string>
#include <iostream>
#include "Skill.h"
using namespace std;

enum  Type { FIRE , WATER, GRASS };

class Pokemon
{
public:
	Pokemon();
	~Pokemon();
	string image="";
protected:
	string name;
	int HP;
	Type type;
	int exp;
	int level;
	int sell_money;
	int Max_hp;
	bool is_evolve=false;

	Skill skill_list[3];
	int skill_idx = 0;

public:
	void set_name(string name);
	string get_name();

	void set_HP(int HP);
	int get_HP();

	void set_type(Type type);
	Type get_type();

	void set_exp(int exp);
	int get_exp();

	void set_level(int level);
	int get_level();

	int get_sell_money();
	void level_up();
	bool evolve();

	Skill *get_skill_list();
	int get_skill_count();
	bool damaged(int damage, Type type);
};

