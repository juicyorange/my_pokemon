#include "Skill.h"



Skill::Skill(string name)
{
	this->name = name;
	if (name == "�Ҳ� �߻�")
		damage = 10;
	else if (name == "ū �Ҳ� �߻�")
		damage = 20;
	else if (name == "��û ū �Ҳ� �߻�")
		damage = 30;

	else if (name == "Ǯ �߻�")
		damage = 10;
	else if (name == "ū Ǯ �߻�")
		damage = 20;
	else if (name == "��û ū Ǯ �߻�")
		damage = 30;

	else if (name == "�� �߻�")
		damage = 10;
	else if (name == "ū �� �߻�")
		damage = 20;
	else if (name == "��û ū �� �߻�")
		damage = 30;

	else if (name == "���� ��Ű��")
		damage = 30;
	else if (name == "���� ��Ű��")
		damage = 50;
	else if (name == "���� ��Ű��")
		damage = 70;

}

Skill::~Skill()
{
}

