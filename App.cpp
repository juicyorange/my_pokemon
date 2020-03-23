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
	//���� ����
	string name;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@@@@@@@@@@@POKEMONSTER@@@@@@@@@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "#���� �̸��� �Է����ּ��� :: ";
	cin >> name;
	user->set_name(name);

	//�̿�: ���ϸ� ����
	cout << "#���ϸ��� �����ϼ���" << endl;
	cout << "#1. ���̸�" << endl;
	cout << "#2. ���α�"<< endl;
	cout << "#3. �̻��ؾ�" << endl;
	cout << "#4. �̽��Ϳ���" << endl;
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

	cout << "���� �̸� :: " << user->get_name() << " ������ ::" << user->get_money() << endl;
	cout << "��ǥ :: " << user->get_pokemon_list()[0]->get_name()
		<< " HP ::" << user->get_pokemon_list()[0]->get_HP()
		<< " level ::" << user->get_pokemon_list()[0]->get_level() 
		<< " exp ::" << user->get_pokemon_list()[0]->get_exp() << endl;

	cout << "-----------------------------------------" << endl;
	cout << "1. �߻����� ������" << endl;
	cout << "2. ���� ���ϸ���� Ȯ���Ѵ�" << endl;
	cout << "3. ���ϸ� ������ �鸰��" << endl;
	cout << "4. ���ϸ� ������ �鸰��" << endl;
	cout << "0. �����Ѵ�." << endl;
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
		cout << "���ϸ� :: " << fight_mon->get_name() << endl;
		cout << "������ :: " << fight_mon->get_level() << endl;
		cout << " H  P  :: " << fight_mon->get_HP() << endl;
		cout << fight_mon->image << endl;
		cout << endl << endl << endl << endl;


		cout << my_mon->image << endl;
		string blanks = "                                      ";
		cout << blanks << " H  P  :: " << my_mon->get_HP() << endl;
		cout << blanks << "������ :: " << my_mon->get_level() << endl;
		cout << blanks << " ���ϸ� :: " << my_mon->get_name() << endl;
		Skill *list = my_mon->get_skill_list();
		int skill_count = my_mon->get_skill_count();

		for (int i = 0; i < skill_count; i++)
		{
			cout << i + 1 << '.' << list[i].name << endl;
		}
		cout << skill_count + 1 << ". ����" << endl;
		cout << "0. ��������" << endl;
		int command;
		cin >> command;

		if (command == 0)
		{
			return;
		}
		//���� ���̸��� 0��°�� ����Ű�µ� �̰Ÿ� ĳ���� �ٲٱ� �ϸ� �ٸ��� ����Ű��
		//�׸��� ����ġ�� if�� check�ؼ� �����ϸ� ����ġ ++
		else if (command >= 1 && command < skill_count + 1)
		{
			int num_exp;
			num_exp = rand() % 10 + 20;
			cout << "���� ���ϸ��� " << list[command - 1].name << "����!";
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
				cout << "�¸�" << endl;
				return;
			}
			system("pause");
		}
		else if (command == skill_count + 1)
		{
			system("cls");
			cout << "����" << endl;
			cout << "1. ȸ����  :: " <<user->get_heal_cnt()<<endl;
			cout << "2. ���ͺ� :: "<<user->get_base_ball()<< endl;
			cout << "3. ���ۺ� :: " << user->get_super_ball()<<endl;
			cout << "4. �����ͺ� :: " << user->get_master_ball()<<endl;
			cout << "5. ���ϸ��� �ٲ۴� " << endl;
			int use; cin >> use;
			system("cls");
			if (use == 1)
			{
				bool check = user->use_heal();
				if (check)
				{
					my_mon->set_HP(my_mon->get_HP() + 20);
					cout << "��ȸ��!" << endl;
				}
			}
			int num_exp;
			num_exp = rand() % 10+20;
			if (1 < use&&use < 5)
			{
				if (user->catch_monster(fight_mon, use - 1))
				{
					cout << "��Ҵ�" << endl;
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
				cout << "����Ҵ�" << endl;
				system("pause");
			}
			else if (use == 5)
			{
				if (user->get_pokemon_size() == 1)
					cout << "���ϸ��� �Ѹ��� �ۿ� �����ϴ�" << endl;
				else
				{
					check_pokemon();
					cout << "�ٲٰ� ���� ���ϸ��� ��ȣ�� �˷��ּ���" << endl;
					int num;
					cin >> num;
					my_mon = user->get_pokemon_list()[num-1];
				}
			}

		}

		int enemy_attack_num = rand() % fight_mon->get_skill_count();

		cout <<"�� ����� " << fight_mon->get_skill_list()[enemy_attack_num].name << " ����!!" << endl;

		int enemy_damage = fight_mon->get_skill_list()[enemy_attack_num].damage;
		bool is_dead = my_mon->damaged(enemy_damage, fight_mon->get_type());
		if (is_dead)
		{
			cout << "���ϸ��� �׾����ϴ�." << endl;
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
	if (name == "���̸�")
		my_mon = new Charmeleon;
	else if (name == "���ڵ�")
		my_mon = new Charizard;
	else if (name == "���α�")
		my_mon = new Wartortle;
	else if (name == "��Ϻα�")
		my_mon = new Blastoise;
	else if (name == "�̻��ؾ�")
		my_mon = new Ivysaur;
	else if (name == "�̻���Ǯ")
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
	cout << "��� ġ��Ǿ����ϴ�" << endl;
	check_pokemon();
}

void App::sell_pokemon()
{
	Pokemon** mon_list = user->get_pokemon_list();
	int mon_list_size = user->get_pokemon_size();
	if (mon_list_size == 1)
	{
		cout << "���ϸ��� �ϳ��ۿ� ���� �ʾ� �Ĵ°� �Ұ���" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < mon_list_size; i++)
	{
		cout <<i+1<<'.'<< mon_list[i]->get_name() << "|";
	}
	cout << "�Ȱ���� ���ϸ��� ��ȣ�� �Է����ּ���" << endl;
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
		cout << "1. ȸ����  :: 1000" << endl;
		cout << "2. ���ͺ� :: 2000" << endl;
		cout << "3. ���ۺ� :: 3000" << endl;
		cout << "4. �����ͺ� :: 5000" << endl;
		cout << "5. ���ϸ� �ȱ�" << endl;
		cout << "6. ��ǥĳ���� �ٲٱ�" << endl;
		cout << "0. ������" << endl;
		int num;
		int money = user->get_money();
		cout << "���� ������ :: " << money << endl;
		cout << "���ڸ� �Է����ּ���" << endl;
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
				cout << "����" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "���� �����մϴ�" << endl;
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
				cout << "�����Ϸ�" << endl;
				system("pause");
	
			}
			else
			{
				system("cls");
				cout << "���� �����մϴ�" << endl;
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
				cout << "�����Ϸ�" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "���� �����մϴ�" << endl;
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
				cout << "�����Ϸ�" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "���� �����մϴ�" << endl;
				system("pause");
			}
			break;
		case 5:
			sell_pokemon();
			break;
		case 6:
		{
			check_pokemon();
			cout << "��ǥ���ͷ� �����ϰ� ���� ĳ������ ��ȣ�� �Է����ּ���" << endl;
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