#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;


struct OPTAB {
	string name[60] = { "ADD","ADDF","ADDR","AND","CLEAR","COMP","COMPF","COMPR","DIV","DIVF","DIVR","FIX","FLOAT","HIO","J","JEQ",
		"JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","MULR","NORM","OR","RD","RMO","RSUB",
		"SHIFTL","SHIFTR","SIO","SSK","STA","STB","STCH","STF","STI","STL","STS","STSW","STT","STX","SUB","SUBF","SUBR","SVC","TD",
		"TIO","TIX","TIXR","WD" };
	string opcode[60] = { "18","58","90","40","B4","28","88","A0","24","64","9C","C4","C0","F4","3C","30","34","38","48","00","68","50","70","08",
		"6C","74","04","D0","20","60","98","C8","44","D8","AC","4C","A4","A8","F0","EC","0C","78","54","80","D4","14","7C","E8",
		"84","10","1C","5C","94","B0","E0","F8","2C","B8","DC" };
};

class SYMTAB {
public:
	string label;
	int targetAddress;
	static int isEmpty;

	void insertLabel(string key, int locationCounter)
	{
		isEmpty = 0;
		label = key;
		targetAddress = locationCounter;
	}
};


static int program_size = 0;
static int no_of_symbols = 0;
static int startingAddress = 0;
static OPTAB optab;
static SYMTAB symtab[20];