#include <iostream>
#include "Number.h"
using namespace std;

int main() {
	Number numar1("10001", 2);
	Number numar2("162", 10);
	Number numar3("16", 7);

	cout << "Exemplu 1" << endl;
	numar1.Print();
	numar1.SwitchBase(16);
	numar1.Print();
	cout << endl;

	cout << "Exemplu 2" << endl;
	numar2.Print();
	numar2.SwitchBase(12);
	numar2.Print();
	cout << endl;

	cout << endl<<"Exemplu 3" << endl;
	numar3.Print();
	numar3.SwitchBase(5);
	numar3.Print();
	cout << endl;

	Number numar4("100", 2);
	Number numar5("10", 2);

	cout << "Exemplu -" << endl;
	Number diferenta = numar4 - numar5;
	diferenta.Print1();

	cout << "Exemplu +" << endl;
	Number suma = numar5 + numar4;
	suma.Print1();

	cout << endl << "Exemplu --numar" << endl;
	numar2--;
	numar2.Print1();

	cout << endl << "Exemplu numar--" << endl;
	--numar2;
	numar2.Print1();
}