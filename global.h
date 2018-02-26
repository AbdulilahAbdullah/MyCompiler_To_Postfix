
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

#define SYMMAX 100
extern ofstream output;
extern ofstream err;
extern ifstream input;
extern int tokenval;
extern int lineno;
extern int lookahead;

struct entry {
	char * lexptr;
	int token;
};

extern struct entry symtable[SYMMAX];