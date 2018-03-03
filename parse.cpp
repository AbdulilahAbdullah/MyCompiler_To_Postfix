#include "global.h"



void parse() {
	lookahead = lexan();
	while (lookahead != DONE) {
		stmt();
		match(';'); output<<endl;
	}
}
void stmt()
{

	while (true)
	{
		int t;
		switch (lookahead)
		{
		case ID:	
			t = tokenval;
			match(ID);
			match('=');
			expr();
			emit(FID, t);
			break;
		case IF:
			
			match(IF);
			match('(');
			expr();
			match(')');
			emit(IF, NONE);
			match(THEN);
			stmt();
			emit(ELSE, NONE);
			break;
		case WHILE:	
			emit(WHILE, NONE);		
			match(WHILE);
			match('(');
			expr();
			match(')');
			emit(AFTERWHILECOND, NONE);
			match(DO);
			stmt();
			emit(ENDWHILE, NONE);
			break;
		case BEGIN:
			emit(BEGIN, NONE);
			match(BEGIN);
			while (1)
			{
				if (lookahead == END)
				{
					match(END);
					break;
				}
					
				stmt();		
				match(';');
			}
			emit(END, NONE);
			break;
		
		default:
			return;

		}

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
