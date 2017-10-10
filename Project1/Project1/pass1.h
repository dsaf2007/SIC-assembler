#pragma once
#include "TABLES.h"
#include "HEXA_DEC.h"


using namespace std;


extern int block_num, line;
extern hexa loc_ctr;
extern string curr_block;
extern bool error_flag;



extern ofstream error;

bool isWhiteSpace(char a);//공백 확인

void extract(string a, string word[], int& count);//a의 공백을 제외하고 단어 단위로 word에 저장.

void execute(string[], int);//pass1의 실질적 기능

void pass1();//end와 start의 경우를 나누어 execute를 실행하고 intermediate에 word작성