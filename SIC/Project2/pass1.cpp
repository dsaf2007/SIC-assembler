#include "pass1.h"
#include "Object.h"
#include "HexDec.h"

#pragma warning(disable : 4996)
int search_symtab_pass1(SYMTAB sym[], string key, int n)
{
	int f = 0, i;
	if (SYMTAB::isEmpty == -1)
		return 0;
	else
	{
		for (i = 0; i<n; i++)
		{
			if (key == sym[i].label)
			{
				f = 1;
				break;
			}
		}
	}

	if (f == 1)
		return 1;
	else
		return 0;
}


int search_optab_pass1(string key)
{
	OPTAB optab;
	int f = 0;
	for (int i = 0; i<60; i++)
	{

		if (key == optab.name[i])
		{
			f = 1;
			break;
		}
	}

	if (f == 1)
		return 1;
	else
		return 0;
}

void pass1()
{
	ifstream fin;
	ofstream fout;
	int LOCCTR, c = 0, lines = 1;
	char ch;
	string opcode[15], op;
	string filename;
	cin >> filename;
	fin.open(filename);
	fout.open("intermediate_file.txt");

	fin >> opcode[0] >> opcode[1] >> opcode[2];   // Reading the first line.

	if (opcode[1] == "START")
	{
		lines++;
		startingAddress = hexToDec(opcode[2]);
		LOCCTR = hexToDec(opcode[2]);
		fout << opcode[0] << "\t" << opcode[1] << "\t" << opcode[2] << endl;

		ch = fin.get();
		ch = fin.get();

		for (int i = 0; ch != '\n'; i++)
		{
			fin >> opcode[i];
			c++;
			ch = fin.get();
		}
	}
	else
		LOCCTR = 0;

	if (c == 2)
		op = opcode[0];
	else
		op = opcode[1];

	int k;
	while (op != "END")
	{
		k = 0;
		if (opcode[k] != ".")
		{
			if (c == 3)
			{
				k = 1;
				int f = search_symtab_pass1(symtab, opcode[0], no_of_symbols);
				if (f == 1)
					cout << "Duplicate Symbol found at line " << lines << endl;
				else
				{
					symtab[no_of_symbols].insertLabel(opcode[0], LOCCTR);
					no_of_symbols++;
				}
			}

			fout << " " << LOCCTR;
			int f = search_optab_pass1(opcode[k]);
			if (f == 1)
				LOCCTR += 3;
			else if (opcode[k] == "WORD")
				LOCCTR += 3;
			else if (opcode[k] == "RESW")
				LOCCTR += 3 * stringToInt(opcode[k + 1]);
			else if (opcode[k] == "RESB")
				LOCCTR += stringToInt(opcode[k + 1]);
			else if (opcode[k] == "BYTE")
			{
				int len;
				if (opcode[k + 1][0] == 'X')
					len = (opcode[k + 1].length() - 3) / 2;
				else
					len = opcode[k + 1].length() - 3;

				LOCCTR += len;
			}
			else
			{
				cout << "Invalid opcode at line " << lines << "is : " << opcode[k] << endl;
			}
		}


		//Writing line to intermediate file
		for (int i = 0; i<c; i++)
			fout << " " << opcode[i];
		fout << endl;


		//Read the next line
		ch = fin.get();
		c = 0;
		for (int i = 0; ch != '\n'; i++)
		{
			fin >> opcode[i];
			c++;
			ch = fin.get();
		}
		if (c == 2 || c == 1)
			op = opcode[0];
		else
			op = opcode[1];

		lines++;

	}

	//Writing last line to intermediate file
	fout << " " << LOCCTR << " ";
	for (int i = 0; i<c; i++)
		fout << opcode[i] << "\n";

	program_size = LOCCTR - startingAddress + 3;
	fin.close();
	fout.close();

}
