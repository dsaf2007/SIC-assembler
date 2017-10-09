#pragma once
#include "TABLES.h"
#include "HEXA_DEC.h"


using namespace std;


static int block_num, line;
static hexa pc;
static string curr_block;
static bool error_flag = 0;



static ofstream error;

bool isWhiteSpace(char a);

void extract(string a, string word[], int& count);

void execute(string[], int);

void run();