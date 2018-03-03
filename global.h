
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
#define FID 259
#define ID 260
#define DONE 261
#define IF 262
#define ELSE 263
#define THEN 264
#define WHILE 265
#define DO 266
#define AFTERWHILECOND 267
#define ENDWHILE 268

#define SYMMAX 100
int lookup(char s[]);
int insert(char s[], int tok);
int lexan();
void emit(int t, int tval);
void expr();
void term();
void match(int);
void factor();
void error(int m);
void init();
void parse();
void stmt();

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
