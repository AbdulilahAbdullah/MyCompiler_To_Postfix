#include "global.h"

void init();
void parse();

ifstream input;
ofstream output;
ofstream err;
int tokenval = NONE;
int lineno = 1;
int lookahead;
struct entry symtable[SYMMAX];

int main() {
	input.open("input.exp");
	output.open("output.obj");
	err.open("error.err");
	

	init();
	parse();
	putchar('\n');
	err << "Compiled successfully";
	output.close();
	input.close();
	err.close();
	return 0;
}
