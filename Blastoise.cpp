#include "Blastoise.h"



Blastoise::Blastoise()
{
	name = "�źϿ�";
	HP = 300;
	Max_hp = 300;
	exp = 0;
	level = 30;
	skill_idx = 2;	//������ �ִ� �ִ� ��ų �� -1
	sell_money = 5000;

	skill_list[skill_idx] = Skill("��û ū �� �߻�");
image="	                   =+++=+++I  M         \n";
image+="                    ?D++?M++++???        	\n";
image+="                     ++++=+???==M        	\n";
image+="                    ==?M=======~         	\n";
image+="      .,M       M~~====Z::====:          	\n";
image+="     .~::. 7M?+++??IIM+?I$$:$    N       	\n";
image+="      .~~II++++++IM+++?ID7N$:.....N      	\n";
image+="       MII+++++IIIII+?IIZII~~:~~~~N      	\n";
image+="      M$II++IIIIII7IIIII$?II:~~~~M       	\n";
image+="      ZII++IIIII$$$$$$$$ZN:::??++~+      	\n";
image+="    MIMIIIIII7$$$$$$$$$$$N,.,???++==M    	\n";
image+="     I$$$$$$$$$$$$$$$$$$$Z:,:?????==?M   	\n";
image+="     $$$$$$7$$7M$$$$$$$$$Z:::M?????N??M  	\n";
image+="     $$$$$$7$$$$$$$$7$$$$~:::= M77?? :   	\n";
image+="     $$$$$$$$Z$$$$7$$$$$::::+~           	\n";
image+="    =$Z$$$$$$$$$$7$$77:::::=~M           	\n";
image+="   =+$$$$$$$$Z$Z$$77,.,.,:++=            	\n";
image+="   +?$ZZZ$$$$M$$$7$,,,,,??++++           	\n";
image+="  M??M$$$$$ZZ$$Z$::,,::?????I??          	\n";
image+="  M?I...,:~:$N::::::,OIIIIIII??          	\n";
image+="   II7===+7D:~~:::::77IIIIIIIII          	\n";
image+="   .~~++I777I=====~,777777777$           	\n";
image+="   M~=?IIII7         77777777M           	\n";
image+="   +?7I???           ,~~77777~M?         	\n";
image+="                     M               		\n";
}


Blastoise::~Blastoise()
{
}
