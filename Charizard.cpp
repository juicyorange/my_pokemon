#include "Charizard.h"



Charizard::Charizard()
{
	name = "리자몽";
	HP = 300;
	Max_hp = 300;
	exp = 0;
	level = 30;
	skill_idx = 2;	//가질수 있는 최대 스킬 수 -1
	sell_money = 5000;

	skill_list[skill_idx] = Skill("엄청 큰 불꽃 발사");
image="	             ~=                       \n";
image+="            M  ??I?+$+                    \n";
image+="        M???   8????????       ?          \n";
image+="      ?OIIZI      =???I         II        \n";
image+="   ?NIIIIIZ7?      M???        ?ZOOI      \n";
image+="  MZIIIIIIOII       +??       ?ZZZ$7I     \n";
image+="  ZIIIIIIIM77I?     +??M     MZI7Z7IIII   \n";
image+=" O7I    IIZ777OOO?  =+??   IMOZIZZZIII7I  \n";
image+=" OM      7$7O8OOOO~=+++?M7OOOO7IZOOZIIIZ  \n";
image+=" O        O  I+??++=~===????=  IO   IM$Z  \n";
image+="           +++   ++=,,:,MM   ==M   I?  O  \n";
image+="           M=D  +=::,,,:~=  M== I  I+: O  \n";
image+="               ==:,:::::~~?        I:+ M  \n";
image+="         IIN ==++:::,::~===        ,::    \n";
image+="      M?IIM?===++===~~====D=?       ?     \n";
image+="     Z????I?=+=??~===~~~~~====    I       \n";
image+="     IIIIII????M~~=====~7??=++?III        \n";
image+="      ?????????+++M    MII????            \n";
image+="          ==?MM             :M,,          \n";
                                         
}

Charizard::~Charizard()
{
}
