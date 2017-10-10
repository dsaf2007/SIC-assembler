#pragma once
#include "TABLES.h"
#include "HEXA_DEC.h"


using namespace std;


extern int block_num, line;
extern hexa locctr;
extern string curr_block;
extern bool error_flag;



extern ofstream error;

bool isWhiteSpace(char a);

void extract(string a, string word[], int& count);

void execute(string[], int);

void pass1();