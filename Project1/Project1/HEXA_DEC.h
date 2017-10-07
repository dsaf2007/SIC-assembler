#pragma once
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdio>
#include<map>

using namespace std;

typedef string hexa;

hexa extendTo(int dig, hexa a);

int toDecDig(char a);

char toHexDig(int a);

string toHex(int a);

int toDec(string val);