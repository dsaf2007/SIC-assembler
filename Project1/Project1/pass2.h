#pragma once
#include<climits>

#include "pass1.h"


using namespace std;

extern ofstream obj, lst, mod;
extern ifstream intm;
extern int curr_block_num;

extern bool imm, ind;

extern string text_s, text_e;
extern int text_length, base;

void modify_object_file();

void input(string a[]);

void pass2();

void assemble(string a[]);

string gen_code(string a[]);