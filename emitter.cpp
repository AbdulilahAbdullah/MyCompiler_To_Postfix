#include "global.h"

void emit(int t, int tval) {
	string nameOfOp;
	switch (t)
	{
	case '+':nameOfOp = "add "; break;
	case '-':nameOfOp = "sub "; break;
	case '*':nameOfOp = "mult"; break;
	case '/':nameOfOp = "Rdiv";
	}

	switch (t)
	{
	case '+': case '-': case '*' : case '/':
		output << "pop r1\n" << "pop r2\n"<< nameOfOp << " r2 ,r1\npush r2\n";
		//output.put(t);
		//output.put(' ');
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
		output << "push " <<tval<<endl;
		break;
	case FID:
		output << "push " << symtable[tval].lexptr << endl;
		break;
	case ID:
		output << "push " << symtable[tval].lexptr << endl;
		break;
	case IF:
		output << "pop r2\ncomp r2 , 0\nBe else\n";
		break;
	case ELSE:
		output << "else\n";
		break;
	case WHILE:
		output << "while\n";
		break;
	case AFTERWHILECOND:
		output << "pop r2\ncmp r2,0\nendwhile\n";
		break;
	case ENDWHILE :
		output << "while\nendwhile\n";
		break;
	default:
		output << "token " << t << ",tokenval " << tval << endl; 
		break;
	}
}
