#pragma once
#include "Object.h"
#pragma warning(disable : 4996)

int stringToInt(string key)
{
	char* intVal;
	intVal=new char[key.length()];
	int value;

	for (int i = 0; i<key.length(); i++)
		intVal[i] = key[i];

	value = atoi(intVal);

	return value;
}


string convertToObject(string opcode, string operand, int *len)
{
	string value, z;
	char hexVal[6];
	int ival;

	ival = stringToInt(operand);    //Returns the integer value to corresponding string passed.

	if (opcode == "WORD")
	{
		itoa(ival, hexVal, 16);   //To convert decimal to hexadecimal

		int i, x = strlen(hexVal);

		for (i = 0; i<6 - x; i++)
		{
			for (int j = x - 1 + i; j >= 0; j--)
				hexVal[j + 1] = hexVal[j];
			hexVal[0] = '0';
		}

		string y(hexVal);
		value = y.substr(0, 6);
		*len = 3;

	}
	else if (opcode == "BYTE")
	{
		if (operand[0] == 'X')
		{
			value = operand.substr(2, operand.length() - 3);
			*len = 1;
		}
		else if (operand[0] == 'C')
		{
			int temp, i;
			char buf[2];
			char* hexVal1;
			hexVal1=new char[(operand.length() - 3) * 2];
			string val;

			for (int i = 2; i<operand.length() - 1; i++)
				hexVal1[i] = operand[i];

			for (i = 2; i<operand.length() - 1; i++)
			{
				temp = hexVal1[i];   //cout<< "ascii value :"<< temp<<endl;

				itoa(temp, buf, 16);  //cout<< "Hexadecimal value :"<< buf<< endl;

				val = buf;
				value = value + val;
			}
			*len = operand.length() - 3;
		}
		else
			value = "n";
	}
	else
		value = "n";

	return value;
}


string object(string m, int add)

{

	char buff[4];

	string val;

	itoa(add, buff, 16);

	val = buff;

	//cout<<m<<endl;

	return(m + val);

}

