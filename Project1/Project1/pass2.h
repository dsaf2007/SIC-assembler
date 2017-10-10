#pragma once
#include<climits>

#include "pass1.h"


using namespace std;

extern ofstream obj, list, mod;
extern ifstream intm;
extern int curr_block_num;

extern bool imm, ind;

extern string text_s, text_e;
extern int text_length, base;

void modify_object_file();//modification file을 읽어와서 string s에 넣는다.

void input(string a[]);//intermediate file을 string a에 입력한다.

void pass2();//intermediate file을 읽어와서 처리한다.

void assemble(string a[]);// 패스2의 명령어를 기계어로 번역하는 기능

string gen_code(string a[]);//objectcode를 생성