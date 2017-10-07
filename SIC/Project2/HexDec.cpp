#pragma once
#include <string.h>
#include "HexDec.h"

int hexToDec(string key)
{
	int sum = 0;
	for (int i = key.length() - 1; i >= 0; i--)
	{
		if (key[i]>'9')
		{
			int var;
			switch (key[i])
			{
			case 'A':
				var = 10;
				break;
			case 'B':
				var = 11;
				break;
			case 'C':
				var = 12;
				break;
			case 'D':
				var = 13;
				break;
			case 'E':
				var = 14;
				break;
			case 'F':
				var = 15;
				break;
			}
			sum += var*pow(16, key.length() - i - 1);
		}
		else
			sum += (key[i] - '0')*pow(16, key.length() - i - 1);
	}

	return sum;

}


string decToHex(string key)
{
	int val;
	char buff[6];
	char* copY;
	copY =new char[key.length()];

	for (int i = 0; i<key.length(); i++)
		copY[i] = key[i];

	val = atoi(copY);

	itoa(val, buff, 16);

	string res(buff);

	return res;
}
