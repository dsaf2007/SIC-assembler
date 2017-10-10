#pragma once
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdio>
#include<map>


using namespace std;


struct info_op
{
	string opcode;
	int format;
	char exist;
	info_op()
	{
		exist = 'n';
	}
};

struct info_reg
{
	int num;
	char exist;
	info_reg()
	{
		exist = 'n';
	}
};
struct info_label
{
	string address;
	string value;
	string block;
	char exist;
	info_label()
	{
		exist = 'n';
	}
};

struct info_block
{
	string address, length;
	int num;
	char exist;
	info_block()
	{
		exist = 'n';
	}
};

typedef string mnemonic, label;

typedef map<mnemonic, info_op>   MapType1;
typedef map<mnemonic, info_reg>  MapType2;
typedef map<label, info_label>   MapType3;
typedef map<label, info_block>   MapType4;


//op �ڵ������.
extern MapType1 OPTAB;

//�������Ϳ� ����
extern MapType2 REGISTER;

//SYMTAB
extern MapType3 SYMTAB;

//programblock
extern MapType4 BLOCK;


int reg_num(char a);//�������� ���� ��ȯ

void create();//optable����

string find_block(int num);