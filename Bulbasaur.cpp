#include "Bulbasaur.h"



Bulbasaur::Bulbasaur()
{
	name = "이상해씨";
	HP = 50;
	Max_hp = 50;
	exp = 0;
	level = 1;
	skill_idx = 0;	//가질수 있는 최대 스킬 수 -1
	sell_money = 1500;

	skill_list[skill_idx] = Skill("풀 발사");
	image = "		 .                          .....  \n";
	image += "  ..  ........  ...............II$I..    \n";
	image += " ..              ..7++======+777I777.    \n";
	image += " ..    .        .+=77777I?+=+==777ZZ.    \n";
	image += " ..  .,=+?. .  .==7777$=====?77777DZ.    \n";
	image += "  ...,,++++,,:+++++??,++I7777777778ZZ    \n";
	image += " .. .,~++++IZZZZI+++++++7I7777777IZZZ?.  \n";
	image += "  ...:++++ZZZZ7+++++++++?$7777777$ZZZZ...\n";
	image += " ...,O++8+++++++++++++++++ZZ77777ZZZDZZ..\n";
	image += " ..+,7$+++++Z+++,++ZZ$+++++$ZZZZZZZZZZZ..\n";
	image += " ..,.ZZ++++O+++?+=I$.77++++++$ZZZZZZOZZZ.\n";
	image += " .+,Z,O+++++++++I.O$.7$+++++ZZZ8ZZZOZZZ~.\n";
	image += " .++++++++++++++...777$+++++ZZZZOZZZZZZ..\n";
	image += " ..?=+++I+?++++++++++++++++++OZZZ+OZZZ.  \n";
	image += " .. ++8$O+++O7$$$$.$7+++++++++++++++.    \n";
	image += "  .  .$+???++???7$?++++I++++7?++?++++.   \n";
	image += "  .. .I~+7++?Z++++++O7++++++77$+OZ+++... \n";
	image += "  .  ..,+O+7777777777,+?Z++77$+ZZZ+++~.  \n";
	image += "  .  ..+~ZZII7$77777,ZZ+I+?777+OZZ+7+,.  \n";
	image += "  .  ..I=Z+II77..77$=ZO+++7I$77+?+++7..  \n";
	image += " ..    .,++7I7.  .O,ZZ+++77..7I77777O    \n";
	image += " ..    ..?Z~7.    .$++++7~. ..?7$777.    \n";
	image += "  ..  ...  ...  ... .7~$ .  .. .  ...    ";
}


Bulbasaur::~Bulbasaur()
{
}
