/*
THIS FILE DEFINES THE OPTABLE, SYMBOL TABLE AND THE REGISTER INFORMATION
TO BE USED THROUGHOUT THE CODE

@AUTHOR: ANUBHAV BINDLISH
B.TECH, CSE 2ND YEAR
IIT ROORKEE
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstdio>
#include<map>
#include<climits>

using namespace std;


//stores info of ach mnemonic instruction
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

typedef std::map<mnemonic, info_op>   MapType1;
typedef std::map<mnemonic, info_reg>  MapType2;
typedef std::map<label, info_label>   MapType3;
typedef std::map<label, info_block>   MapType4;
//USING MAPS ALLOWS SEARCHING FOR ANY ENTRY IN LOG(N) TIME

//This maps the instructions(mnemonic codes) with thier Opcode and their format
MapType1 OPTAB;

//This maps the register mnemonic with their number
MapType2 REGISTER;

//This map forms the symbol table : Label and  Address
MapType3 SYMTAB;

//This maps the program block name with its info
MapType4 BLOCK;



int reg_num(char a)
{
	if (a == 'A') return 0;
	if (a == 'X') return 1;
	if (a == 'L') return 2;
	if (a == 'B') return 3;
	if (a == 'S') return 4;
	if (a == 'T') return 5;
	if (a == 'F') return 6;
}


/*---------OPTABLE-----------*/
void create()
{

	OPTAB["ADD"].opcode = "18";
	OPTAB["ADD"].format = 3;
	OPTAB["ADD"].exist = 'y';

	OPTAB["ADDF"].opcode = "58";
	OPTAB["ADDF"].format = 3;
	OPTAB["ADDF"].exist = 'y';

	OPTAB["ADDR"].opcode = "90";
	OPTAB["ADDR"].format = 2;
	OPTAB["ADDR"].exist = 'y';

	OPTAB["AND"].opcode = "40";
	OPTAB["AND"].format = 3;
	OPTAB["AND"].exist = 'y';

	OPTAB["CLEAR"].opcode = "B4";
	OPTAB["CLEAR"].format = 2;
	OPTAB["CLEAR"].exist = 'y';

	OPTAB["COMP"].opcode = "28";
	OPTAB["COMP"].format = 3;
	OPTAB["COMP"].exist = 'y';

	OPTAB["COMPF"].opcode = "88";
	OPTAB["COMPF"].format = 3;
	OPTAB["COMPF"].exist = 'y';

	OPTAB["COMPR"].opcode = "A0";
	OPTAB["COMPR"].format = 2;
	OPTAB["COMPR"].exist = 'y';

	OPTAB["DIV"].opcode = "24";
	OPTAB["DIV"].format = 3;
	OPTAB["DIV"].exist = 'y';

	OPTAB["DIVF"].opcode = "64";
	OPTAB["DIVF"].format = 3;
	OPTAB["DIVF"].exist = 'y';

	OPTAB["DIVR"].opcode = "9C";
	OPTAB["DIVR"].format = 2;
	OPTAB["DIVR"].exist = 'y';

	OPTAB["FIX"].opcode = "C4";
	OPTAB["FIX"].format = 1;
	OPTAB["FIX"].exist = 'y';

	OPTAB["FLOAT"].opcode = "C0";
	OPTAB["FLOAT"].format = 1;
	OPTAB["FLOAT"].exist = 'y';

	OPTAB["HIO"].opcode = "F4";
	OPTAB["HIO"].format = 1;
	OPTAB["HIO"].exist = 'y';

	OPTAB["J"].opcode = "3C";
	OPTAB["J"].format = 3;
	OPTAB["J"].exist = 'y';

	OPTAB["JEQ"].opcode = "30";
	OPTAB["JEQ"].format = 3;
	OPTAB["JEQ"].exist = 'y';

	OPTAB["JGT"].opcode = "34";
	OPTAB["JGT"].format = 3;
	OPTAB["JGT"].exist = 'y';

	OPTAB["JLT"].opcode = "38";
	OPTAB["JLT"].format = 3;
	OPTAB["JLT"].exist = 'y';

	OPTAB["JSUB"].opcode = "48";
	OPTAB["JSUB"].format = 3;
	OPTAB["JSUB"].exist = 'y';

	OPTAB["LDA"].opcode = "00";
	OPTAB["LDA"].format = 3;
	OPTAB["LDA"].exist = 'y';

	OPTAB["LDB"].opcode = "68";
	OPTAB["LDB"].format = 3;
	OPTAB["LDB"].exist = 'y';

	OPTAB["LDCH"].opcode = "50";
	OPTAB["LDCH"].format = 3;
	OPTAB["LDCH"].exist = 'y';

	OPTAB["LDF"].opcode = "70";
	OPTAB["LDF"].format = 3;
	OPTAB["LDF"].exist = 'y';

	OPTAB["LDL"].opcode = "08";
	OPTAB["LDL"].format = 3;
	OPTAB["LDL"].exist = 'y';

	OPTAB["LDS"].opcode = "6C";
	OPTAB["LDS"].format = 3;
	OPTAB["LDS"].exist = 'y';

	OPTAB["LDT"].opcode = "74";
	OPTAB["LDT"].format = 3;
	OPTAB["LDT"].exist = 'y';

	OPTAB["LDX"].opcode = "04";
	OPTAB["LDX"].format = 3;
	OPTAB["LDX"].exist = 'y';

	OPTAB["LPS"].opcode = "D0";
	OPTAB["LPS"].format = 3;
	OPTAB["LPS"].exist = 'y';

	OPTAB["MUL"].opcode = "20";
	OPTAB["MUL"].format = 3;
	OPTAB["MUL"].exist = 'y';

	OPTAB["MULF"].opcode = "60";
	OPTAB["MULF"].format = 3;
	OPTAB["MULF"].exist = 'y';

	OPTAB["MULR"].opcode = "98";
	OPTAB["MULR"].format = 2;
	OPTAB["MULR"].exist = 'y';

	OPTAB["NORM"].opcode = "C8";
	OPTAB["NORM"].format = 1;
	OPTAB["NORM"].exist = 'y';

	OPTAB["OR"].opcode = "44";
	OPTAB["OR"].format = 3;
	OPTAB["OR"].exist = 'y';

	OPTAB["RD"].opcode = "D8";
	OPTAB["RD"].format = 3;
	OPTAB["RD"].exist = 'y';

	OPTAB["RMO"].opcode = "AC";
	OPTAB["RMO"].format = 2;
	OPTAB["RMO"].exist = 'y';

	OPTAB["RSUB"].opcode = "4C";
	OPTAB["RSUB"].format = 3;
	OPTAB["RSUB"].exist = 'y';

	OPTAB["SHIFTL"].opcode = "A4";
	OPTAB["SHIFTL"].format = 2;
	OPTAB["SHIFTL"].exist = 'y';

	OPTAB["SHIFTR"].opcode = "A8";
	OPTAB["SHIFTR"].format = 2;
	OPTAB["SHIFTR"].exist = 'y';

	OPTAB["SIO"].opcode = "F0";
	OPTAB["SIO"].format = 1;
	OPTAB["SIO"].exist = 'y';

	OPTAB["SSK"].opcode = "EC";
	OPTAB["SSK"].format = 3;
	OPTAB["SSK"].exist = 'y';

	OPTAB["STA"].opcode = "0C";
	OPTAB["STA"].format = 3;
	OPTAB["STA"].exist = 'y';

	OPTAB["STB"].opcode = "78";
	OPTAB["STB"].format = 3;
	OPTAB["STB"].exist = 'y';

	OPTAB["STCH"].opcode = "54";
	OPTAB["STCH"].format = 3;
	OPTAB["STCH"].exist = 'y';

	OPTAB["STF"].opcode = "80";
	OPTAB["STF"].format = 3;
	OPTAB["STF"].exist = 'y';

	OPTAB["STI"].opcode = "D4";
	OPTAB["STI"].format = 3;
	OPTAB["STI"].exist = 'y';

	OPTAB["STL"].opcode = "14";
	OPTAB["STL"].format = 3;
	OPTAB["STL"].exist = 'y';

	OPTAB["STS"].opcode = "7C";
	OPTAB["STS"].format = 3;
	OPTAB["STS"].exist = 'y';

	OPTAB["STSW"].opcode = "E8";
	OPTAB["STSW"].format = 3;
	OPTAB["STSW"].exist = 'y';

	OPTAB["STT"].opcode = "84";
	OPTAB["STT"].format = 3;
	OPTAB["STT"].exist = 'y';

	OPTAB["STX"].opcode = "10";
	OPTAB["STX"].format = 3;
	OPTAB["STX"].exist = 'y';

	OPTAB["SUB"].opcode = "1C";
	OPTAB["SUB"].format = 3;
	OPTAB["SUB"].exist = 'y';

	OPTAB["SUBF"].opcode = "5C";
	OPTAB["SUBF"].format = 3;
	OPTAB["SUBF"].exist = 'y';

	OPTAB["SUBR"].opcode = "94";
	OPTAB["SUBR"].format = 2;
	OPTAB["SUBR"].exist = 'y';

	OPTAB["SVC"].opcode = "B0";
	OPTAB["SVC"].format = 2;
	OPTAB["SVC"].exist = 'y';

	OPTAB["TD"].opcode = "E0";
	OPTAB["TD"].format = 3;
	OPTAB["TD"].exist = 'y';

	OPTAB["TIO"].opcode = "F8";
	OPTAB["TIO"].format = 1;
	OPTAB["TIO"].exist = 'y';

	OPTAB["TIX"].opcode = "2C";
	OPTAB["TIX"].format = 3;
	OPTAB["TIX"].exist = 'y';

	OPTAB["TIXR"].opcode = "B8";
	OPTAB["TIXR"].format = 2;
	OPTAB["TIXR"].exist = 'y';

	OPTAB["WD"].opcode = "DC";
	OPTAB["WD"].format = 3;
	OPTAB["WD"].exist = 'y';

	/*-------------------------*/



	/*---REGISTERS'-INFO-------*/

	REGISTER["A"].num = 0;
	REGISTER["A"].exist = 'y';

	REGISTER["X"].num = 1;
	REGISTER["X"].exist = 'y';

	REGISTER["L"].num = 2;
	REGISTER["L"].exist = 'y';

	REGISTER["B"].num = 3;
	REGISTER["B"].exist = 'y';

	REGISTER["S"].num = 4;
	REGISTER["S"].exist = 'y';

	REGISTER["T"].num = 5;
	REGISTER["T"].exist = 'y';

	REGISTER["F"].num = 6;
	REGISTER["F"].exist = 'y';

	REGISTER["PC"].num = 8;
	REGISTER["PC"].exist = 'y';

	REGISTER["SW"].num = 9;
	REGISTER["SW"].exist = 'y';

	/*--------------------------*/

}


string find_block(int num)
{
	for (MapType4::const_iterator it = BLOCK.begin();; ++it)
		if (it->second.num == num)
			return it->first;
}


typedef string hexa;

hexa extendTo(int dig, hexa a)
{
	hexa temp = "";
	for (int i = 0; i<dig - a.length(); ++i)
		temp += '0';
	return temp + a;
}

int toDecDig(char a)
{
	if (a == '0') return 0;
	if (a == '1') return 1;
	if (a == '2') return 2;
	if (a == '3') return 3;
	if (a == '4') return 4;
	if (a == '5') return 5;
	if (a == '6') return 6;
	if (a == '7') return 7;
	if (a == '8') return 8;
	if (a == '9') return 9;
	if (a == 'A') return 10;
	if (a == 'B') return 11;
	if (a == 'C') return 12;
	if (a == 'D') return 13;
	if (a == 'E') return 14;
	if (a == 'F') return 15;
}


char toHexDig(int a)
{
	if (a == 0) return '0';
	if (a == 1) return '1';
	if (a == 2) return '2';
	if (a == 3) return '3';
	if (a == 4) return '4';
	if (a == 5) return '5';
	if (a == 6) return '6';
	if (a == 7) return '7';
	if (a == 8) return '8';
	if (a == 9) return '9';
	if (a == 10) return 'A';
	if (a == 11) return 'B';
	if (a == 12) return 'C';
	if (a == 13) return 'D';
	if (a == 14) return 'E';
	if (a == 15) return 'F';
}

string toHex(int a)
{
	string res = "";
	while (a>0)
	{
		res = toHexDig(a % 16) + res;
		a /= 16;
	}
	return res;
}


int toDec(string val)
{
	int l = val.length() - 1, curr = 1, res = 0;
	while (l >= 0)
	{
		res += (toDecDig(val[l])*curr);
		curr *= 16;
		--l;
	}
	return res;
}


bool isWhiteSpace(char a)

{

	if (a == ' ')  return true;

	if (a == '\t') return true;

	return false;

}



void extract(string a, string word[], int& count)

{

	int i;

	for (i = 0; i<5; ++i) word[i] = "";

	count = 0;

	i = 0;

	while (isWhiteSpace(a[i]) && i<a.length()) { ++i; continue; }

	if (i == a.length() || a[i] == '.')   return;

	for (; i<a.length();)

	{

		while (isWhiteSpace(a[i]) && i<a.length()) { ++i; continue; }

		if (i == a.length()) break;

		for (; !isWhiteSpace(a[i]) && i<a.length(); ++i) word[count] += a[i];

		++count;

	}

}



void execute(string[], int);



int block_num, line;

hexa pc;

string curr_block;

bool error_flag = 0;





ifstream fin1;

ofstream fout1, error;



void run()

{

	create();

	char ch;

	string s, word[5];

	int count = 0;

	fin1.open("input_palindrome.txt");

	fout1.open("intermediate.txt");

	error.open("error.txt");

	line = 5;

	getline(fin1, s);

	extract(s, word, count);

	while (count == 0)

	{

		fout1 << line << endl;

		fout1 << "$";

		fout1 << s << endl;

		fout1 << "" << endl;

		fout1 << "" << endl;

		line += 5;

		cout << "s: " << s << endl;

	}

	pc = "0";

	BLOCK["DEFAULT"].num = 0;

	BLOCK["DEFAULT"].address = pc;

	BLOCK["DEFAULT"].length = "0";

	BLOCK["DEFAULT"].exist = 'y';

	curr_block = "DEFAULT";

	block_num = 1;

	line = 5;

	if (word[0] == "START")

	{

		pc = word[1];

		fout1 << line << endl;

		fout1 << "" << endl;

		fout1 << "START" << endl;

		fout1 << pc << endl;

		fout1 << pc << endl;

		fout1 << "" << endl;

		cout << "0 is start!" << endl;

	}

	else if (word[1] == "START")

	{

		pc = word[2];

		fout1 << line << endl;

		fout1 << word[0] << endl;

		fout1 << "START" << endl;

		fout1 << pc << endl;

		fout1 << pc << endl;

		fout1 << "" << endl;

		cout << "1 is start!" << endl;

	}

	else

		execute(word, count);

	while (true)

	{

		getline(fin1, s);

		extract(s, word, count);

		line += 5;

		cout << "s: " << s << endl;

		fout1 << line << endl;

		if (count == 0)

		{

			cout << "Comment detected!" << endl;

			fout1 << "$" << endl;

			fout1 << s << endl;

			fout1 << "" << endl;

			fout1 << "" << endl;

			fout1 << "" << endl;

			continue;

		}

		if (word[0] == "END")

		{

			BLOCK[curr_block].length = pc;

			fout1 << "" << endl;

			fout1 << word[0] << endl;

			fout1 << word[1] << endl;

			fout1 << pc << endl;

			fout1 << "" << endl;

			break;

		}

		execute(word, count);

		// cin>>ch;

	}

	hexa addr, len;

	string temp = find_block(0);

	addr = BLOCK[temp].address;

	len = BLOCK[temp].length;

	for (int i = 1; i<block_num; ++i)

	{

		temp = find_block(i);

		BLOCK[temp].address = toHex(toDec(addr) + toDec(len));

		addr = BLOCK[temp].address;

		len = BLOCK[temp].length;



	}

}



void execute(string word[], int count)

{

	cout << "word[0]: " << word[0] << " pc: " << pc << endl;

	if (word[0] == "USE")

	{

		cout << "USE detected!" << endl;

		BLOCK[curr_block].length = pc;

		if (word[1] == "")

		{

			curr_block = "DEFAULT";

			pc = BLOCK["DEFAULT"].length;

		}

		else if (BLOCK[word[1]].exist == 'y')

		{

			curr_block = word[1];

			pc = BLOCK[word[1]].length;

		}

		else

		{

			BLOCK[word[1]].num = block_num;

			BLOCK[word[1]].exist = 'y';

			BLOCK[word[1]].length = "0";

			curr_block = word[1];

			pc = "0";

			++block_num;

		}

		fout1 << "" << endl;

		fout1 << word[0] << endl;

		fout1 << word[1] << endl;

		fout1 << pc << endl;

		fout1 << "" << endl;

		return;

	}

	if (word[0][0] == '+')

	{

		cout << "Format 4" << endl;

		fout1 << "" << endl;

		fout1 << word[0] << endl;

		fout1 << word[1] << endl;

		fout1 << pc << endl;

		pc = toHex(toDec(pc) + 4);

		fout1 << pc << endl;

		return;

	}

	if (OPTAB[word[0]].exist == 'y')

	{

		cout << "0 is opcode!" << endl;

		fout1 << "" << endl;

		fout1 << word[0] << endl;

		fout1 << word[1] << endl;

		fout1 << pc << endl;

		pc = toHex(toDec(pc) + OPTAB[word[0]].format);

		fout1 << pc << endl;

		return;

	}

	if (OPTAB[word[0]].exist == 'n')

	{

		if (SYMTAB[word[0]].exist == 'y')

		{

			error << "Line " << line << ": Duplicate Symbol" << endl;

			error_flag = 1;

		}

		else

		{

			SYMTAB[word[0]].address = pc;

			SYMTAB[word[0]].block = curr_block;

			SYMTAB[word[0]].exist = 'y';

			fout1 << word[0] << endl;

			fout1 << word[1] << endl;

			fout1 << word[2] << endl;

			fout1 << pc << endl;

			if (word[1][0] == '+')

				pc = toHex(toDec(pc) + 4);

			else if (OPTAB[word[1]].exist == 'y')

				pc = toHex(toDec(pc) + OPTAB[word[1]].format);

			else if (word[1] == "WORD")      pc = toHex(toDec(pc) + 3);

			else if (word[1] == "RESW")      pc = toHex(toDec(pc) + (atoi(word[2].c_str()) * 3));

			else if (word[1] == "RESB")      pc = toHex(toDec(pc) + atoi(word[2].c_str()));

			else if (word[1] == "BYTE")

			{

				int len = word[1].length() - 3;

				if (word[1][0] == 'X') len /= 2;

				pc = toHex(toDec(pc) + len);

			}

			else

			{

				error << "Line " << line << ": Opcode not found" << endl;

				error_flag = 1;

			}

			fout1 << pc << endl;

		}

	}

}

ofstream obj, lst, mod;

ifstream intm;

int curr_block_num;



void modify_object_file()

{

	ifstream fin;

	fin.open("modification.txt");

	string s;

	while (true)

	{

		getline(fin, s);

		if (s == "") break;

		obj << s << endl;

	}

	//fin.close();

}



bool imm, ind;



void input(string a[])

{

	int i;

	for (i = 0; i<6; ++i)

		getline(intm, a[i]);

	cout << "Input for line: " << a[0] << endl;

	for (i = 1; i<6; ++i)

		cout << a[i] << endl;

}



void assemble(string[]);

string gen_code(string[]);



string text_s = "", text_e = "";

int text_length = 0, base = INT_MAX;



int main()

{

	run();

	string a[6];

	char ch;

	hexa start;

	if (error_flag)

	{

		cout << "Errors encountered! Listing file not prepared!" << endl;

		cout << "Have a look at the error file to know more!" << endl;

		exit(1);

	}

	intm.open("intermediate.txt");

	obj.open("object.txt");

	lst.open("list.txt");

	mod.open("modification.txt");

	lst << "Line\tLoc   Block\t\tSource Statement\t\tObject Code" << endl;

	lst << "----------------------------------------------------------------" << endl << endl;

	input(a);

	curr_block = "DEFAULT";

	curr_block_num = 0;

	while (a[1] == "$")

	{

		lst << a[0] << "\t\t " << a[2] << endl;

		input(a);

	}

	if (a[2] == "START")

	{

		lst << a[0] << "\t" << extendTo(4, a[4]) << "  " << curr_block_num << "\t\t" << a[1] << "\t\t" << a[2] << "\t\t" << a[3] << endl;

		obj << "H^";

		int i;

		for (i = 0; i<a[1].length(); ++i)

			obj << a[1][i];

		for (; i<6; ++i)

			obj << " ";

		string temp = find_block(block_num - 1);

		hexa len;

		len = toHex(toDec(BLOCK[temp].address) + toDec(BLOCK[temp].length));

		obj << "^" << extendTo(6, a[3]) << "^" << extendTo(6, len) << endl;

		start = a[3];

	}

	else

	{

		error_flag = 1;

		error << "Intermediate File has no start!" << endl;

	}

	while (true)

	{

		input(a);

		if (a[1] == "$")

		{

			lst << a[0] << "\t\t " << a[2] << endl;

			continue;

		}

		if (a[2] == "END")

		{

			lst << a[0] << "\t\t\t\t\t\t" << a[2] << "\t\t" << a[3] << endl;

			if (text_length>0)

			{

				obj << text_s << "^" << extendTo(2, toHex(text_length / 2)) << text_e << endl;

				cout << "!!" << endl;

			}

			text_length = 0;

			text_s = "";

			text_e = "";

			modify_object_file();

			obj << "E^" << extendTo(6, start) << endl;

			break;

		}

		// cout<<a[2]<<endl;

		assemble(a);

		cout << "opcode: " << a[2] << ":::";

		// cin>>ch;

	}

	if (error_flag)

	{

		cout << "Errors encountered! Listing file not prepared!" << endl;

		cout << "Have a look at the error file to know more!" << endl;

	}

	else

	{

		cout << "INPUT FILE ASSEMBLED SUCCESSFULY!!" << endl;

	}

}



void assemble(string a[])

{

	string object_code;

	hexa loc_ctr;

	int format;

	if (a[2] == "USE")

	{

		curr_block = a[3];

		curr_block_num = BLOCK[curr_block].num;

		lst << a[0] << "\t0000  " << curr_block_num << "\t\t\t" << a[2] << "\t\t" << a[3] << endl;

		if (text_length>0) obj << text_s << "^" << extendTo(2, toHex(text_length / 2)) << text_e << endl;

		text_s = "";

		text_e = "";

		text_length = 0;

		return;

	}

	if (a[2] == "RESB" || a[2] == "RESW")

	{

		lst << a[0] << "\t" << extendTo(4, a[4]) << "  " << curr_block_num << "\t\t" << a[1] << "\t" << a[2] << "\t\t" << a[3] << endl;

		if (text_length>0) obj << text_s << "^" << extendTo(2, toHex(text_length / 2)) << text_e << endl;

		text_s = "";

		text_e = "";

		text_length = 0;

		return;

	}

	imm = ind = false;

	object_code = gen_code(a);

	cout << "a[2]: " << a[2] << ":::" << object_code << endl;

	if (a[2] == "BYTE" || a[2] == "WORD")

		lst << a[0] << "\t" << extendTo(4, a[4]) << "  " << curr_block_num << "\t\t" << a[1] << "\t" << a[2] << "\t\t" << a[3] << endl;

	else

	{

		if (imm)      lst << a[0] << "\t" << extendTo(4, a[4]) << "  " << curr_block_num << "\t\t" << a[1] << "\t\t" << a[2] << "\t\t#" << a[3] << "\t\t" << object_code << endl;

		else if (ind) lst << a[0] << "\t" << extendTo(4, a[4]) << "  " << curr_block_num << "\t\t" << a[1] << "\t\t" << a[2] << "\t\t@" << a[3] << "\t\t" << object_code << endl;

		else         lst << a[0] << "\t" << extendTo(4, a[4]) << "  " << curr_block_num << "\t\t" << a[1] << "\t\t" << a[2] << "\t\t" << a[3] << "\t\t" << object_code << endl;

	}

	if (text_s == "")

	{

		loc_ctr = toHex(toDec(BLOCK[curr_block].address) + toDec(a[4]));

		text_s = "T^" + extendTo(6, loc_ctr);

		text_e = "^" + object_code;

		text_length = object_code.length();

	}

	else if (text_length + object_code.length()>60)

	{

		obj << text_s << "^" << extendTo(2, toHex(text_length / 2)) << text_e << endl;

		loc_ctr = toHex(toDec(BLOCK[curr_block].address) + toDec(a[4]));

		text_s = "T^" + extendTo(6, loc_ctr);

		text_e = "^" + object_code;

		text_length = object_code.length();

	}

	else

	{

		text_e += "^" + object_code;

		text_length += object_code.length();

	}

	if (a[2] == "LDB")

	{

		base = toDec(SYMTAB[a[3]].address) + toDec(BLOCK[SYMTAB[a[3]].block].address);

	}

}



string gen_code(string a[])

{

	string ob1, ob2, ob3;

	hexa operand_addr, prgm_ctr;

	int format;

	if (a[2] == "BYTE")

	{

		int i;

		ob1 = "";

		if (a[3][0] == 'X')

			for (i = 2; i<a[3].length() - 1; ++i) ob1 += a[3][i];

		else //a[3][0]=='C'

			for (i = 2; i<a[3].length() - 1; ++i)

				ob1 += toHex((int)a[3][i]);

		return ob1;

	}

	if (a[2] == "WORD")

	{

		ob1 = toHex(atoi(a[3].c_str()));

		return ob1;

	}

	if (a[2] == "RSUB")

	{

		ob1 = "4F0000";

		return ob1;

	}

	if (a[2] == "+RSUB")

	{

		ob1 = "4F000000";

		return ob1;

	}

	if (a[2][0] == '+')

	{

		format = 4;

		a[2] = a[2].substr(1);

	}

	else

		format = OPTAB[a[2]].format;

	if (format == 1)

	{

		cout << "Format 1" << endl;

		ob1 = OPTAB[a[2]].opcode;

		return ob1;

	}

	if (format == 2)

	{

		cout << "Format 2" << endl;

		ob1 = OPTAB[a[2]].opcode;

		if (a[3].length() == 3)

		{

			ob2 = toHex(reg_num(a[3][0]));

			if (isdigit(a[3][2]))  ob2 = ob2 + toHexDig(a[3][2] - 1);

			else

			{

				ob2 = ob2 + toHexDig(reg_num(a[3][2]));

			}

		}

		else  //a[3].length==1

		{

			if (isdigit(a[3][0]))

			{

				ob2 = toHex(atoi(a[3].c_str())) + "0";

				cout << "isdigit! ob2: " << ob2 << endl;

			}

			else

			{

				cout << toHex(reg_num(a[3][0])) << endl;

				ob2 = toHex(reg_num(a[3][0])) + "0";

				cout << "Not Isdigit! ob2: " << ob2 << endl;

			}

		}

		cout << "a[2]: " << a[2] << " ob1:" << ob1 << "ob2:" << ob2 << endl;

		return (ob1 + extendTo(2, ob2));

	}

	if (format == 3)

	{

		cout << "Format 3" << endl;

		cout << a[2] << endl;

		ob1 = OPTAB[a[2]].opcode;

		if (a[3][0] == '#')

		{

			imm = true;

			cout << "Immediate!" << endl;

			ob1 = toHex(toDec(ob1) + 1);

			a[3] = a[3].substr(1);

			if (isdigit(a[3][0]))

			{

				ob2 = "0";

				ob3 = toHex(atoi(a[3].c_str()));

				return extendTo(2, ob1) + ob2 + extendTo(3, ob3);

			}

			//cout<<"ob1: "<<ob1<<endl;

		}

		else if (a[3][0] == '@')

		{

			ind = true;

			cout << "Indirect!" << endl;

			ob1 = toHex(toDec(ob1) + 2);

			a[3] = a[3].substr(1);

		}

		else

			ob1 = toHex(toDec(ob1) + 3);

		ob2 = "0";

		bool x = false;

		if (a[3][a[3].length() - 2] == ',')

		{

			x = true;

			ob2 = toHex(toDec(ob2) + 8);

			a[3] = a[3].substr(0, a[3].length() - 2);

		}

		//cout<<"ob1:"<<ob1<<"ob2:"<<ob2<<endl;

		prgm_ctr = toHex(toDec(BLOCK[curr_block].address) + toDec(a[5]));

		operand_addr = toHex(toDec(SYMTAB[a[3]].address) + toDec(BLOCK[SYMTAB[a[3]].block].address));

		cout << "prgm_ctr: " << prgm_ctr << " operand_addr: " << operand_addr << endl;

		if (x) a[3] += ",X";

		int disp = toDec(operand_addr) - toDec(prgm_ctr);

		cout << "disp: " << disp << endl;

		if (disp >= -2048 && disp<2048)

		{

			ob2 = toHex(toDec(ob2) + 2);

			if (disp<0) disp += 4096;

			ob3 = toHex(disp);

			return extendTo(2, ob1) + extendTo(1, ob2) + extendTo(3, ob3);

		}

		disp = toDec(operand_addr) - base;

		if (disp >= -2048 && disp<2048)

		{

			ob2 = toHex(toDec(ob2) + 4);

			if (disp<0) disp += 4096;

			ob3 = toHex(disp);

			return extendTo(2, ob1) + extendTo(1, ob2) + extendTo(3, ob3);

		}

		//If still here, means overflow

		error_flag = 1;

		error << "Line " << a[0] << ": Overflow detected" << endl;

	}

	if (format == 4)

	{

		ob1 = OPTAB[a[2]].opcode;

		if (a[3][0] == '#')

		{

			imm = true;

			ob1 = toHex(toDec(ob1) + 1);

			a[3] = a[3].substr(1);

			if (isdigit(a[3][0]))

			{

				ob2 = "0";

				ob3 = toHex(atoi(a[3].c_str()));

				a[2] = "+" + a[2];

				return ob1 + ob2 + extendTo(5, ob3);

			}

		}

		else if (a[3][0] == '@')

		{

			ind = true;

			ob1 = toHex(toDec(ob1) + 2);

			a[3] = a[3].substr(1);

		}

		else

			ob1 = toHex(toDec(ob1) + 3);

		bool x = false;

		ob2 = "1";

		if (a[3][a[3].length() - 2] == ',')

		{

			x = true;

			ob2 = toHex(toDec(ob2) + 8);

			a[3] = a[3].substr(0, a[3].length() - 2);

		}

		operand_addr = toHex(toDec(SYMTAB[a[3]].address) + toDec(BLOCK[SYMTAB[a[3]].block].address));

		if (x) a[3] += ",X";

		ob3 = operand_addr;

		a[2] = "+" + a[2];

		hexa loc_ctr = toHex(toDec(BLOCK[curr_block].address) + toDec(a[4]) + 1);

		mod << "M^" << extendTo(6, loc_ctr) << "^05" << endl;

		return extendTo(2, ob1) + extendTo(1, ob2) + extendTo(5, ob3);

	}

}