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

void modify_object_file();//modification file�� �о�ͼ� string s�� �ִ´�.

void input(string a[]);//intermediate file�� string a�� �Է��Ѵ�.

void pass2();//intermediate file�� �о�ͼ� ó���Ѵ�.

void assemble(string a[]);// �н�2�� ��ɾ ����� �����ϴ� ���

string gen_code(string a[]);//objectcode�� ����