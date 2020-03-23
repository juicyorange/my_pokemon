#include "Wartortle.h"



Wartortle::Wartortle()
{
	name = "어니부기";
	HP = 150;
	Max_hp = 150;
	exp = 0;
	level = 15;
	skill_idx = 1;	//가질수 있는 최대 스킬 수 -1
	sell_money = 2000;

	skill_list[skill_idx] = Skill("큰 물 발사");

image="	      N,,                ,,          \n";  
image+="      ,,,             O,::N              \n";
image+="     M,:N,           ,Z::N               \n";
image+="      ,:::  ~==~~=  ,:::,,               \n";
image+="      ,::~~=~=~=~~=,,:,,,.               \n";
image+="     :::,:~~~~~~~~=,::::,                \n";
image+="      :~~~~~~~~~~=~,:,::                 \n";
image+="       =~~~~~~==~:~+:,,       ,,,::::    \n";
image+="       ~D~~~~~~N  :???,      ,,,::~:,N   \n";
image+="       ~,N~~~~~7N.,???~IN   ,::::::::    \n";
image+="       ~=N=~~~~~N+77??~~~~~=~N:::ZM=     \n";
image+="  +~~~~~M?~~~~~=O8:?$?=====~~~ N:~~:,    \n";
image+=".:~==~~=??,,N??DDN~~~???==~~N +D:N:M?    \n";
image+=" ?::?????N,,,,N.,,,,,,??????8::::N,:,,   \n";
image+="     7O??I.,,,,,,,,,,,:~~:7+?:::::,,N,:  \n";
image+="         D..,,,,,,,,,,:~~~7II:~~:::,,,:  \n";
image+="          ...,,N,,,,,,O~~~~II~~:::,,::=  \n";
image+="          M..,,,,,,,,~~~~??NZ~~~::::::   \n";
image+="         =~M,,,,N,,,~~~??????~~~::::M    \n";
image+="        ~~==+,,,.:N~~~N==+????::::M      \n";
image+="       O==++?II~~~~~~~==~~=~=??          \n";
image+="        IIIIIIN        I::~~???          \n";
image+="       IIIIIID          ????????         \n";
image+="         N               ??+??+=         \n";
image+="                            D          	 \n";
}


Wartortle::~Wartortle()
{
}
