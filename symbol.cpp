#include "global.h"
#define STRMAX 999
void error(int m);


char lexemes[STRMAX];
int lastchar = -1;
int lastentry = 0;

int lookup(char s[]) {
	int p;
	for (p = lastentry; p > 0; p--)
		if (strcmp(symtable[p].lexptr, s) == 0)
			return p;

	return 0;
}

int insert(char s[], int tok) {
	int len;
	len = strlen(s);

	if (lastentry + 1 >= SYMMAX)
		error(1);

	if (lastchar + len + 1 >= STRMAX)
		error(2);

	lastentry++;

	symtable[lastentry].token = tok;
	symtable[lastentry].lexptr = &lexemes[lastchar+1];

	lastchar = lastchar + len + 1;
	strcpy(symtable[lastentry].lexptr, s);

	return lastentry;
}