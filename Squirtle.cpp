#include "Squirtle.h"



Squirtle::Squirtle()
{
	name = "���α�";
	HP = 50;
	Max_hp = 50;
	exp = 0;
	level = 1;
	skill_idx = 0;	//������ �ִ� �ִ� ��ų �� -1
	sell_money = 2000;

	skill_list[skill_idx] = Skill("�� �߻�");
image="	         :::======~                   \n";
image+="         ==~========++M                   \n";
image+="        .+=======  M+++$                  \n";
image+="        M=======DMD~+???                  \n";
image+="       M========78?,????M                 \n";
image+="       ~===========?????M                 \n";
image+="       ?????????DZ?M????                  \n";
image+="        ???????????????,                  \n";
image+="          ++??????????=N=                 \n";
image+="       ===++=M?????M+??MI+                \n";
image+="    ~~===~::=+++++=:=+??MI+               \n";
image+=" ++=====::,~:~~=+=~===???IIM              \n";
image+=" ??====~:::,:=:~M=====++=I++              \n";
image+="MM?????=~::::M~:==?=+++M:I++              \n";
image+="       ~:::~:~:=?????++=,I??              \n";
image+="       :Z:M~~::~~~~~++M==7II     MMM      \n";
image+="       M~~~~~~~~~~~++++=:777  ======??    \n";
image+="      ~=:~::~~~~~=++====M77  ++++?????M   \n";
image+="     M:~=+=~::~+++~======MMM???????????   \n";
image+="     ::==?N=++++++=======??????O??????D   \n";
image+="     ==+????M+++++==~~===?????????????    \n";
image+="    D+?????M       =====+?????????MO      \n";
image+="    M+7??M         M??????                \n";
image+="                    +?????                \n";
image+="                       M             	  \n";
}												


Squirtle::~Squirtle()
{
}
