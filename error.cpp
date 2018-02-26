#include "global.h"

void error(int m) {
	err << "ERROR: Line ";
	switch(m)
	{
	case 0:
		err << lineno << " : Expression is missing a factor.";
		break;
	case 1:
		err << lineno << " : Symbol table is full.";
		break;
	case 2:
		err << lineno << " : Lexemes array is full.";
		break;
	case 3:
		err << lineno << " :Compiler error \'IDentifier is too long.\'";
		break;
	default:
		err << lineno << " : "; err.put(m); err << " is expected before the statement. "; err.put(m);
	}
	output.close(); output.open("output.obj");
	output << "An error occurred. Check error file for more info.";
	exit(1);
}