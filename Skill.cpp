#include "Skill.h"



Skill::Skill(string name)
{
	this->name = name;
	if (name == "불꽃 발사")
		damage = 10;
	else if (name == "큰 불꽃 발사")
		damage = 20;
	else if (name == "엄청 큰 불꽃 발사")
		damage = 30;

	else if (name == "풀 발사")
		damage = 10;
	else if (name == "큰 풀 발사")
		damage = 20;
	else if (name == "엄청 큰 풀 발사")
		damage = 30;

	else if (name == "물 발사")
		damage = 10;
	else if (name == "큰 물 발사")
		damage = 20;
	else if (name == "엄청 큰 물 발사")
		damage = 30;

	else if (name == "맥주 시키기")
		damage = 30;
	else if (name == "소주 시키기")
		damage = 50;
	else if (name == "고량주 시키기")
		damage = 70;

}

Skill::~Skill()
{
}

