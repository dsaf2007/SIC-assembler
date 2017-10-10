#pragma once
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdio>
#include<map>

using namespace std;

typedef string hexa;

hexa extendTo(int dig, hexa a);//dig-a.length만큼 a앞에 0추가

int toDecDig(char a);

char toHexDig(int a);

string toHex(int a);//10진수->16진수

int toDec(string val);//16진수->10진수