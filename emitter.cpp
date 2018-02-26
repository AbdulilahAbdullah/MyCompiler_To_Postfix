#include "global.h"
void emit(int t, int tval) {
	string nameOfOp;
	switch (t)
	{
	case '+':nameOfOp = "add"; break;
	case '-':nameOfOp = "sub"; break;
	case '*':nameOfOp = "mult"; break;
	case '/':nameOfOp = "Rdiv";
	}

	switch (t)
	{
	case '+': case '-': case '*' : case '/':
		output << "pop r1\n" << "pop r2\n"<< nameOfOp << " r2 ,r1\npush r2\n";
		//output.put(t);
		break;
	case DIV:
		output << "pop r1\npop r2\nDiv r2 ,r1\npush r2\n";
		//output << "DIV ";
		break;
	case MOD:
		output << "pop r1\npop r2\nMOD r2 ,r1\npush r2\n";
		//output << "MOD ";
		break;
	case NUM:
		output << "push " << tval << endl;
		break;
	case ID:
		output << "push " << symtable[tval].lexptr << endl;
		break;
	default:
		output << "token " << t << ",tokenval " << tval << endl; 
		break;
	}
}