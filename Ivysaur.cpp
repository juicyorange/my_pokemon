#include "Ivysaur.h"



Ivysaur::Ivysaur()
{
	name = "이상해풀";
	HP = 150;
	Max_hp = 150;
	exp = 0;
	level = 15;
	skill_idx = 1;	//가질수 있는 최대 스킬 수 -1
	sell_money = 3500;
	skill_list[skill_idx] = Skill("큰 풀 발사");

image="                M                       	   \n";
image+="              M  7===                    	   \n";
image+="              ~=+N===??      777         	   \n";
image+="             +~++===+???+ II 777?7       	   \n";
image+="             ~=?I==+????$+7777777M       	   \n";
image+="            ?+==N+????I?$$$7$$77777      	   \n";
image+="   ??I 77 7 ?????????I$$$$$77I7I7N       	   \n";
image+="   ??II777MII7IM7IIIIMMM$$Z???II7M=+M    	   \n";
image+=" III???IIIMI77M7M$$7I7M+?==+++++=ZZM7    	   \n";
image+=" II???M?777777$$$$$77ZMD++==++==$Z+Z++   	   \n";
image+="  ?N??77777I$$$$$$M$$7++++?.I7M?=+++++?  	   \n";
image+="   IM77$$77$$$$$7$$$$+++++I.M??N+++++++, 	   \n";
image+="      M 77$$$$$$MM777=+=+++=+=+?I7II++I7 	   \n";
image+="           ZM77$$M777===+++?M:III77IIII, 	   \n";
image+="       MI77$ZO$7OO77=++++?III7777777I?   	   \n";
image+="     ?IIIII$M77OOZ===+??+?7II7777????    	   \n";
image+="      7IIOZM=++OZ+===++++?777777I?7      	   \n";
image+="      M7M M==++==+I===M++I777777777+     	   \n";
image+="          M$====?77+=+$ZDIM7777777ZZ     	   \n";
image+="          $Z$+$7777+=+MZZ7777 777IIZM    	   \n";
image+="          ZZ+777M777++M=?77   777MI++    	   \n";
image+="          ?+777I    M+8=II7    77777?    	   \n";
image+="          777=7=     NIIIIIM    M,::M    	   \n";
image+="                        D                	   \n";
}


Ivysaur::~Ivysaur()
{
}
