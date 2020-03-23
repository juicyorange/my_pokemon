#include "Monsterball.h"
#include <ctime>


Monsterball::Monsterball()
{
}


Monsterball::~Monsterball()
{
}

string Monsterball::get_name()
{
	return name;
}

int Monsterball::get_pro()
{
	return pro;
}

bool Monsterball::catch_mon()
{
	int num;
	srand(time(NULL));
	num = rand() % 101;

	if (num <= pro)
	{
		return true;
	}
	return false;

}