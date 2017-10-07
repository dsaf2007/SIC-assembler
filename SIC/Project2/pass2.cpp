#include "pass2.h"
#include "Object.h"
#pragma warning(disable : 4996)
using namespace std;


int search_symtab_pass2(SYMTAB sym[], string key, int n)
{
	int f = -1, i;
	if (SYMTAB::isEmpty == -1)
		return 0;
	else
	{
		for (i = 0; i<n; i++)
		{
			if (key == sym[i].label)
			{
				f = i;
				break;
			}
		}
	}

	if (f == -1)
		return f;
	else
		return f;
}


string search_optab_pass2(string key)
{
	OPTAB optab;
	string f = "n";
	for (int i = 0; i<60; i++)
	{

		if (key == optab.name[i])
		{
			f = optab.opcode[i];
			break;
		}
	}

	if (f == "n")
		return "n";
	else
		return f;
}


void pass2()
{
	ifstream fin;
	ofstream fout;
	string opcode[10], op;
	char ch;
	int c = 0, sizeCount = 0, pointerPos = 0, y = 0, z = 1 ,t=0;

	fin.open("intermediate_file.txt");
	fout.open("output.txt");

	fin >> opcode[0] >> opcode[1] >> opcode[2];   // Reading the first line.

	if (opcode[1] == "START")
	{
		fout << "OBJECT PROGRAM" << endl << endl;
		char buff[6];
		itoa(program_size - 3, buff, 16);
		fout << "H^" << setw(6) << setfill('_') << opcode[0] << "^" << setw(6) << setfill('0') << opcode[2] << "^" << setw(6) << setfill('0') << buff << endl << endl;

		ch = fin.get();
		ch = fin.get();

		for (int i = 0; ch != '\n'; i++)
		{
			fin >> opcode[i];
			c++;
			ch = fin.get();
		}
		if (opcode[0] == ".")
			op = opcode[0];
		else if (c == 3)
			op = opcode[1];
		else
			op = opcode[2];
	}

	fout << "T^" << setw(6) << setfill('0') << decToHex(opcode[0]) << "^  ";
	pointerPos = fout.tellp();
	while (op != "END")
	{
		if (op != ".")
		{
			int x = 0;
			string value;
			string m = search_optab_pass2(op);
			if (m != "n")
			{
				if (c >= 3)
				{
					int k = 0;
					if (opcode[c - 1].substr(opcode[c - 1].length() - 2, 2) == ",X")
					{
						k = 1;
						opcode[c - 1] = opcode[c - 1].substr(0, opcode[c - 1].length() - 2);
					}

					int f = search_symtab_pass2(symtab, opcode[c - 1], no_of_symbols);
					if (f != -1)
					{
						int val;
						if (k == 1)
							val = symtab[f].targetAddress + 32768;
						else
							val = symtab[f].targetAddress;

						value = object(m, val);
					}
					else
					{
						opcode[3] = "0000";
						value = m + opcode[3];
						cout << "Undefined Symbol!! " << opcode[2] << endl;
					}
				}
				else
				{
					opcode[3] = "0000";
					value = m + opcode[3];
				}
				sizeCount += 3;
			}
			else if (op == "BYTE" || op == "WORD")   //Finding the object code of byte and word.
			{
				int byteLen = 0;
				if (c == 3)
					value = convertToObject(op, opcode[2], &byteLen);
				else
					value = convertToObject(op, opcode[3], &byteLen);

				if (value == "n")
					cout << "Invalid opcode!!!";

				if (op == "WORD")
					sizeCount += byteLen;
				else
					sizeCount += byteLen;

			}
			else    //To check the break point of text record.
			{
				x = 1;
				z = 0;
			}

			if (sizeCount>30 || x == 1)   //Checking the text record size availability.
			{
				if (y != 1)    //This condition prevents the change in the file pointer every time.
				{
					if (sizeCount>30)
						sizeCount -= 3;
					char buff[6];
					itoa(sizeCount, buff, 16);
					t = fout.tellp();
					pointerPos = t - pointerPos;
					fout.seekp(-pointerPos - 2, ios_base::cur);   //Writing the text record size to output file.
					fout << setw(2) << setfill('0') << buff;
					fout.seekp(0, ios_base::end);
				}
				y = 1;
			}

			if (x != 1 && y == 1)
			{
				y = 0;
				z = 1;
				sizeCount = 3;
				fout << "\nT^" << setw(6) << setfill('0') << decToHex(opcode[0]) << "^  ";    //Creating the new text record.
				pointerPos = fout.tellp();
			}

			//Writing text record to output file
			if (x != 1)
			{
				fout << "^" << value;
			}
			//cout<< sizeCount<<endl;
		}

		//Read the next line
		ch = fin.get();
		c = 0;
		for (int i = 0; ch != '\n'; i++)
		{
			fin >> opcode[i];
			c++;
			ch = fin.get();
		}
		if (c == 2 || c == 3)
			op = opcode[1];
		else
			op = opcode[2];

	}

	if (z == 1)    // This condition checks if there are no resw or resb instructions at end of program then it sets the text record size.
	{
		char buff[6];
		itoa(sizeCount, buff, 16);
		t = fout.tellp();
		pointerPos =t - pointerPos;
		fout.seekp(-pointerPos - 2, ios_base::cur);   //Writing the text record size to output file.
		fout << setw(2) << setfill('0') << buff;
		fout.seekp(0, ios_base::end);
	}

	//Writing last text record to output file
	char buf[6];
	itoa(startingAddress, buf, 16);
	fout << "\n\nE^" << setw(6) << setfill('0') << buf;

	fin.close();
	fout.close();
}

