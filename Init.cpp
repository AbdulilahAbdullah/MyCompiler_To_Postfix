#include "global.h"
struct entry keywords[] = {
	{(char*)"div", DIV},
	{(char*)"mod", MOD},
	{0, 0}
};

int insert(char s[], int tok);

void init() {
	struct entry *p;
	for (p = keywords; p->token; p++)
		insert(p->lexptr, p->token);
}