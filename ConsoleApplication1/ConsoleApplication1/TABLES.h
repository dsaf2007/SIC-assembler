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

//stores info of ach mnemonic instruction
typedef map<mnemonic, info_op>   MapType1;
typedef map<mnemonic, info_reg>  MapType2;
typedef map<label, info_label>   MapType3;
typedef map<label, info_block>   MapType4;
//USING MAPS ALLOWS SEARCHING FOR ANY ENTRY IN LOG(N) TIME

//This maps the instructions(mnemonic codes) with thier Opcode and their format
static MapType1 OPTAB;

//This maps the register mnemonic with their number
static MapType2 REGISTER;

//This map forms the symbol table : Label and  Address
static MapType3 SYMTAB;

//This maps the program block name with its info
static MapType4 BLOCK;


int reg_num(char a);

void create();

string find_block(int num);