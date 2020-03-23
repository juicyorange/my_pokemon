#pragma once
#include <string>
using namespace std;

struct Skill
{
public:
	Skill()
	{
	}
	Skill(string name);
	~Skill();

public:
	int damage;
	string name;
};
