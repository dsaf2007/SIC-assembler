#pragma once
#include "TABLES.h"
#include "HEXA_DEC.h"


using namespace std;


extern int block_num, line;
extern hexa loc_ctr;
extern string curr_block;
extern bool error_flag;



extern ofstream error;

bool isWhiteSpace(char a);//���� Ȯ��

void extract(string a, string word[], int& count);//a�� ������ �����ϰ� �ܾ� ������ word�� ����.

void execute(string[], int);//pass1�� ������ ���

void pass1();//end�� start�� ��츦 ������ execute�� �����ϰ� intermediate�� word�ۼ�