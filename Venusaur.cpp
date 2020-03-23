#include "Venusaur.h"



Venusaur::Venusaur()
{
	name = "이상해꽃";
	HP = 300;
	Max_hp = 300;
	exp = 0;
	level = 30;
	skill_idx = 2;	//가질수 있는 최대 스킬 수 -1
	sell_money = 4500;

	skill_list[skill_idx] = Skill("엄청 큰 풀 발사");

	image = "	              M++M    MM             \n";
	image += "            MMN8=?IIIMIM+=:=+            \n";
	image += "       M??+++M+:=++==?II==N+=::?M        \n";
	image += "      ??:M?++::++:+888I=+++:+?O???       \n";
	image += "      I M???????? O88M8 +????+?I??+      \n";
	image += "         ?IIIII  888888M I~~??IID        \n";
	image += "            MIZOOI777ZZMZIIIII           \n";
	image += "     ID777$$ZZZZZM$IOOZMZZZZZ$$77$       \n";
	image += "  IIIII7$$$++DZ7777777777M++IO$$77D77    \n";
	image += " ?III77777$M$I+$M77777777+?$I$$7777II?II \n";
	image += "  ??7 7$Z$ZZ?+++I77II77Z?????ZZZZMMDIMI7 \n";
	image += "     $$$778++I++++M?DM??+?:??I$$$$$7     \n";
	image += "     7$$IM?++  :++++??++$  ?I7I7$8$$7    \n";
	image += "    MO77I7I77I?+++++????IIM777$7$$$$$    \n";
	image += "     $$Z77777IZ+++IDID+++Z7M$777$7OZ     \n";
	image += "      ZZN7777$I$+======+7I77$777$ZZ      \n";
	image += "         $$$7$7OI7MMMMMIN$7$$77$M        \n";
	image += "          M$$$$         $77$$$$          \n";
	image += "                       :$$$$$M           \n";
	image += "                         M  M         	 \n";
}


Venusaur::~Venusaur()
{
}
