#include "legend.h"



legend::legend()
{
	name = "박형준";
	HP = 100;
	Max_hp = 100;
	exp = 0;
	level = 1;
	skill_idx = 2;	//가질수 있는 최대 스킬 수 -1
	sell_money = 10000;
	
	skill_list[skill_idx - 2] = Skill("맥주 시키기");
	skill_list[skill_idx - 1] = Skill("소주 시키기");
	skill_list[skill_idx ] = Skill("고량주 시키기");

image="	--:+syy::::::/+/+++++/:----------::::--:   \n";
image+="--:/oso::///+ssssssssoo/::::::---:::::::	   \n";
image+="---:++/--::/ssyyyyyyyssos+:::----:::::::	   \n";
image+="---:///---:oyyyso+///:/+yyo:-----///////	   \n";
image+=":-:::::---/yys+/::------+hs:::---ssssoos	   \n";
image+="::::------:s/://:::::/::-s+::::::hhhhhhh	   \n";
image+="-----------/:/+o+///+++/:////////ddddddd	   \n";
image+=".....--::::--:/+/:-:/++/:/ddddddhddddddd	   \n";
image+=".``..--....-/++::---::++//ddddddhddddddd	   \n";
image+="```...-````.-:+//+++:::/::hdddddhddddddd	   \n";
image+=".`.....```...--:++++//:/++osydddhyhhdddd	   \n";
image+=".......``.....-:oo++/++yssso//+osoosyyyh	   \n";
image+=".......-...--:+yhhhyyyhdyysssooo+o+++oos	   \n";
image+=".......y+/:/shdmmmmmmdmdhhysssyysoo++++o	   \n";
image+="-..---:dhdmmddddmmmdddddhhhyyyyhdsssoooo	   \n";
image+="::--:/+hdddddmdmdmmdmmddhdhhhhhddsssssss	   \n";
image+="o++++oshhhdmdddddhhdddddddhhhddddyssyyyy	   \n";
image+="yyyhhhhdddmmmdddddddddddddhhdddmdyyyyyyh	   \n";
image+="ddmmmdddddNNmdddddddddddddhdddmmhyyhhhhh	   \n";
image+="dddddddddmNNmddddmmdddddddhddmmmohhhhhhd	   \n";

}


legend::~legend()
{
}
