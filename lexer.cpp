#include "global.h"

char lexbuf[BSIZE];

int lookup(char s[]);
int insert(char s[], int tok);
void error(int m);

int lexan() {
	int t;
	char c;
	while (input.get(c)) {
		t = c;
		if (t == ' ' || t == '\t');
		else if (t == '\n') lineno++;
		else if (isdigit(t)) 
		{
			input.putback(t);
			input >> tokenval;
			return NUM;
		}
		else if (isalpha(t)) {
			int p, b = 0;
			while (isalnum(t)) {
				lexbuf[b] = t;
				input.get(c);
				t = c;
				b++;
				if (b >= BSIZE)
					error(3);
			}

			lexbuf[b] = EOS;
			if (!(input.eof()))
				input.putback(t);
			p = lookup(lexbuf);
			if (p == 0)
				p = insert(lexbuf, ID);
			tokenval = p;
			return symtable[p].token;
		}
		else {
			tokenval = NONE;
			return t;
		}
	}
	if (input.eof())
		return DONE;
}