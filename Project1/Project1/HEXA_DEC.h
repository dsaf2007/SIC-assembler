#pragma once
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdio>
#include<map>

using namespace std;

typedef string hexa;

hexa extendTo(int dig, hexa a);//dig-a.length��ŭ a�տ� 0�߰�

int toDecDig(char a);

char toHexDig(int a);

string toHex(int a);//10����->16����

int toDec(string val);//16����->10����