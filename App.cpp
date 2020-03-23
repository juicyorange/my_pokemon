#include "App.h"
#include <ctime>


App::App()
{
	user = new User();
}


App::~App()
{
	delete user;
}

void App::run()
{
	start_game();

	bool running = true;

	while (running)
	{
		print_menu();

		int command = -1;
		cin >> command;
		switch (command)
		{
		case 1:
			system("cls");
			fight();
			system("cls");
			break;
		case 2:
			system("cls");
			check_pokemon();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			shop();
			system("cls");
			break;
		case 4:
			system("cls");
			all_heal();
			system("pause");
			system("cls");
			break;
		case 0:
			running = false;
			break;
		default:
			break;
		}
	}
	return;
}

void App::start_game()
{
	//유저 설정
	string name;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@@@@@@@@@@@POKEMONSTER@@@@@@@@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "#유저 이름을 입력해주세요 :: ";
	cin >> name;
	user->set_name(name);

	//미완: 포켓몬 선택
	cout << "#포켓몬을 선택하세요" << endl;
	cout << "#1. 파이리" << endl;
	cout << "#2. 꼬부기"<< endl;
	cout << "#3. 이상해씨" << endl;
	cout << "#4. 이스터에그" << endl;
	int command = -1;
	cin >> command;
	switch (command)
	{
	case 1:
		user->gain_pokemon(new Charmander());
		break;
	case 2:
		user->gain_pokemon(new Squirtle());
		break;
	case 3:
		user->gain_pokemon(new Bulbasaur());
		break;
	case 4:
		user->gain_pokemon(new legend());
	default:
		break;
	}
	system("pause");
	system("cls");
}

void App::print_menu()
{

	cout << "유저 이름 :: " << user->get_name() << " 소지금 ::" << user->get_money() << endl;
	cout << "대표 :: " << user->get_pokemon_list()[0]->get_name()
		<< " HP ::" << user->get_pokemon_list()[0]->get_HP()
		<< " level ::" << user->get_pokemon_list()[0]->get_level() 
		<< " exp ::" << user->get_pokemon_list()[0]->get_exp() << endl;

	cout << "-----------------------------------------" << endl;
	cout << "1. 야생으로 떠난다" << endl;
	cout << "2. 나의 포켓몬들을 확인한다" << endl;
	cout << "3. 포켓몬 상점에 들린다" << endl;
	cout << "4. 포켓몬 병원에 들린다" << endl;
	cout << "0. 종료한다." << endl;
}



void App::fight()
{
	Pokemon* my_mon = user->get_pokemon_list()[0];
	system("cls");
	int num; Pokemon *fight_mon = nullptr;
	srand(time(NULL));
	num = rand() % 6;
	int level_set = rand() % 6;
	if (num == 0)
	{
		fight_mon = new Charmander;
	}
	else if (num == 1)
	{
		fight_mon = new Bulbasaur;

	}
	else if (num == 2)
	{
		fight_mon = new Squirtle;
	}
	else if (num == 3)
	{
		fight_mon = new Charmeleon;
	}
	else if (num == 4)
	{
		fight_mon = new Ivysaur;
	}
	else if (num == 5)
	{
		fight_mon = new Wartortle;
	}

	if (my_mon->get_level() < 5)
		fight_mon->set_level(level_set+1);
	else
		fight_mon->set_level(my_mon->get_level() - 5 + level_set+1);
	while (true)
	{
		cout << "포켓몬 :: " << fight_mon->get_name() << endl;
		cout << "레에벨 :: " << fight_mon->get_level() << endl;
		cout << " H  P  :: " << fight_mon->get_HP() << endl;
		cout << fight_mon->image << endl;
		cout << endl << endl << endl << endl;


		cout << my_mon->image << endl;
		string blanks = "                                      ";
		cout << blanks << " H  P  :: " << my_mon->get_HP() << endl;
		cout << blanks << "레에벨 :: " << my_mon->get_level() << endl;
		cout << blanks << " 포켓몬 :: " << my_mon->get_name() << endl;
		Skill *list = my_mon->get_skill_list();
		int skill_count = my_mon->get_skill_count();

		for (int i = 0; i < skill_count; i++)
		{
			cout << i + 1 << '.' << list[i].name << endl;
		}
		cout << skill_count + 1 << ". 가방" << endl;
		cout << "0. 도망가기" << endl;
		int command;
		cin >> command;

		if (command == 0)
		{
			return;
		}
		//지금 마이몬은 0번째를 가리키는데 이거를 캐릭터 바꾸기 하면 다른걸 가리키게
		//그리고 경험치는 if로 check해서 만족하면 경험치 ++
		else if (command >= 1 && command < skill_count + 1)
		{
			int num_exp;
			num_exp = rand() % 10 + 20;
			cout << "나의 포켓몬의 " << list[command - 1].name << "공격!";
			int my_damage = list[command - 1].damage;
			bool is_dead = fight_mon->damaged(my_damage, my_mon->get_type());
			if (is_dead)
			{
				for (int i = 0; i < user->get_pokemon_size();i++)
				{
					user->get_pokemon_list()[i]->set_exp(num_exp);
					bool is_evolve = user->get_pokemon_list()[i]->evolve();
					if (is_evolve)
					{
						evolve_mon(user->get_pokemon_list()[i]);
					}

				}
				user->set_money(user->get_money() + 2000);
				cout << "승리" << endl;
				return;
			}
			system("pause");
		}
		else if (command == skill_count + 1)
		{
			system("cls");
			cout << "가방" << endl;
			cout << "1. 회복약  :: " <<user->get_heal_cnt()<<endl;
			cout << "2. 몬스터볼 :: "<<user->get_base_ball()<< endl;
			cout << "3. 슈퍼볼 :: " << user->get_super_ball()<<endl;
			cout << "4. 마스터볼 :: " << user->get_master_ball()<<endl;
			cout << "5. 포켓몬을 바꾼다 " << endl;
			int use; cin >> use;
			system("cls");
			if (use == 1)
			{
				bool check = user->use_heal();
				if (check)
				{
					my_mon->set_HP(my_mon->get_HP() + 20);
					cout << "피회복!" << endl;
				}
			}
			int num_exp;
			num_exp = rand() % 10+20;
			if (1 < use&&use < 5)
			{
				if (user->catch_monster(fight_mon, use - 1))
				{
					cout << "잡았다" << endl;
					for (int i = 0; i < user->get_pokemon_size();i++)
					{
						user->get_pokemon_list()[i]->set_exp(num_exp);
						bool is_evolve = user->get_pokemon_list()[i]->evolve();
						if (is_evolve)
						{
							evolve_mon(user->get_pokemon_list()[i]);
						}
					}
					user->set_money(user->get_money() + 2000);
					system("pause");
					return;
				}
				cout << "못잡았다" << endl;
				system("pause");
			}
			else if (use == 5)
			{
				if (user->get_pokemon_size() == 1)
					cout << "포켓몬이 한마리 밖에 업습니다" << endl;
				else
				{
					check_pokemon();
					cout << "바꾸고 싶은 포켓몬의 번호를 알려주세요" << endl;
					int num;
					cin >> num;
					my_mon = user->get_pokemon_list()[num-1];
				}
			}

		}

		int enemy_attack_num = rand() % fight_mon->get_skill_count();

		cout <<"저 썅년의 " << fight_mon->get_skill_list()[enemy_attack_num].name << " 공격!!" << endl;

		int enemy_damage = fight_mon->get_skill_list()[enemy_attack_num].damage;
		bool is_dead = my_mon->damaged(enemy_damage, fight_mon->get_type());
		if (is_dead)
		{
			cout << "포켓몬이 죽었습니다." << endl;
			return;
		}

		
		system("pause");
		system("cls");
	}
}
void App::evolve_mon(Pokemon * my_mon)
{
	string name = my_mon->get_name();
	delete my_mon;
	if (name == "파이리")
		my_mon = new Charmeleon;
	else if (name == "리자드")
		my_mon = new Charizard;
	else if (name == "꼬부기")
		my_mon = new Wartortle;
	else if (name == "어니부기")
		my_mon = new Blastoise;
	else if (name == "이상해씨")
		my_mon = new Ivysaur;
	else if (name == "이상해풀")
		my_mon = new Venusaur;

		
}

void App::check_pokemon()
{
	Pokemon** mon_list = user->get_pokemon_list();
	int mon_list_size = user->get_pokemon_size();
	for (int i = 0; i < mon_list_size; i++)
	{
		cout << i + 1 << ".";
		cout << mon_list[i]->get_name() << "|"
			<< "   HP:" << mon_list[i]->get_HP()
			<< "   exp:" << mon_list[i]->get_exp()
			<< "   level:" << mon_list[i]->get_level() << endl;
	}
}

void App::all_heal()
{
	for (int i = 0;i < user->get_pokemon_size();i++)
		user->get_pokemon_list()[i]->set_HP(99999999);
	cout << "모두 치료되었습니다" << endl;
	check_pokemon();
}

void App::sell_pokemon()
{
	Pokemon** mon_list = user->get_pokemon_list();
	int mon_list_size = user->get_pokemon_size();
	if (mon_list_size == 1)
	{
		cout << "포켓몬이 하나밖에 남지 않아 파는게 불가능" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < mon_list_size; i++)
	{
		cout <<i+1<<'.'<< mon_list[i]->get_name() << "|";
	}
	cout << "팔고싶은 포켓몬의 번호를 입력해주세요" << endl;
	int temp;
	cin >> temp;
	if (temp <= mon_list_size)
	{
		user->set_money(user->get_money()+user->get_pokemon_list()[temp - 1]->get_sell_money());
		user->del_pokemon_list(temp-1);
	}
}

void App::shop()
{
	for (; ;)
	{
		system("cls");
		cout << "1. 회복약  :: 1000" << endl;
		cout << "2. 몬스터볼 :: 2000" << endl;
		cout << "3. 슈퍼볼 :: 3000" << endl;
		cout << "4. 마스터볼 :: 5000" << endl;
		cout << "5. 포켓몬 팔기" << endl;
		cout << "6. 대표캐릭터 바꾸기" << endl;
		cout << "0. 나가기" << endl;
		int num;
		int money = user->get_money();
		cout << "현재 소지금 :: " << money << endl;
		cout << "숫자를 입력해주세요" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			if (money > 1000)
			{
				user->set_heal(user->get_heal() + 1);
				user->set_money(user->get_money() - 1000);
				system("cls");
				cout << "충전" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "돈이 부족합니다" << endl;
				system("pause");
			}
			break;
		}
		break;
		case 2:
		{
			if (money >= 2000)
			{
				user->set_base_ball(user->get_base_ball() + 1);
				user->set_money(user->get_money() - 2000);
				system("cls");
				cout << "충전완료" << endl;
				system("pause");
	
			}
			else
			{
				system("cls");
				cout << "돈이 부족합니다" << endl;
				system("pause");
			}
			break;
		}
		break;
		case  3:
		{
			if (money >= 3000)
			{
				user->set_super_ball(user->get_super_ball() + 1);
				user->set_money(user->get_money() - 3000);
				system("cls");
				cout << "충전완료" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "돈이 부족합니다" << endl;
				system("pause");
			}
			break;
		}
		case 4:
			if (money >= 5000)
			{
				user->set_master_ball(user->get_master_ball() + 1);
				user->set_money(user->get_money() - 5000);
				system("cls");
				cout << "충전완료" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "돈이 부족합니다" << endl;
				system("pause");
			}
			break;
		case 5:
			sell_pokemon();
			break;
		case 6:
		{
			check_pokemon();
			cout << "대표몬스터로 지정하고 싶은 캐릭터의 번호를 입력해주세요" << endl;
			int num;
			cin >> num;
			Pokemon *temp = user->get_pokemon_list()[num - 1];
			user->set_pokemon(user->get_pokemon_list()[0], num - 1);
			user->set_pokemon(temp, 0);
			system("cls");
			system("pause");
			break;
		}
		case 0:
			return;
		default:
			break;
		}
	}
}