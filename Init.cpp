#include "global.h"
struct entry keywords[] = {
	{(char*)"div", DIV},
	{(char*)"mod", MOD},
	{(char*)"if", IF },
	{(char*)"then",THEN},
	{(char*)"while" ,WHILE},
	{(char*)"do",DO},
	{(char*)"begin",BEGIN},
	{(char*)"end" , END},
	{0, 0}
};


void init() {
	struct entry *p;
	for (p = keywords; p->token; p++)
		insert(p->lexptr, p->token);
}
