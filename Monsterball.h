#pragma once
#include <string>
#include "pokemon.h"
using namespace std;
class Monsterball
{
protected:
	string name;
	int pro;
	int money;
public:
	Monsterball();
	~Monsterball();

	string get_name();
	int get_pro();
	bool catch_mon();
};

