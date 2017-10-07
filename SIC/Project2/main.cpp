#include "Object.h"
#include "pass1.h"
#include "pass2.h"

int SYMTAB::isEmpty = -1;

void main()
{
	pass1();

	cout << "Pass 1 : All done!!" << endl << endl;



	pass2();

	cout << "Pass 2 : All done!!" << endl << endl;

	cout << "Check out the output file. :-)" << endl;


}