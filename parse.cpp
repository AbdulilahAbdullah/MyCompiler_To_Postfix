#include "global.h"

int lexan();
void emit(int t, int tval);
void error(int m);
void expr();
void term();
void match(int);
void factor();


void parse() {
	lookahead = lexan();
	while (lookahead != DONE) {
		expr(); 
		match(';'); output<<endl<<endl<<endl;
	}
}

void expr() {
	int t;
	term();

	while (true)
		switch (lookahead)
		{
		case '+': case '-':
			t = lookahead;
			match(lookahead); term(); emit(t, NONE);
			continue;
		default:
			return;
		}
	
}

void term() {
	int t;
	factor();
	while(true)
		switch (lookahead)
		{
		case '*': case '/': case DIV: case MOD:
			t = lookahead;
			match(lookahead); factor(); emit(t, NONE);
			continue;
		default:
			return;
		}
}

void factor() {
	switch (lookahead)
	{
	case '(':
		match('('); expr(); match(')');
		break;
	case NUM:
		emit(NUM, tokenval);
		match(NUM); break;
	case ID:
		emit(ID, tokenval);
		match(ID);
		break;
	default:
		error(0);
	}
}


void match(int t) {
	if (lookahead == t)
		lookahead = lexan();
	else
		error(t);
}