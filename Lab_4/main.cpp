#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
	cout << "Exemplul 1, lista cu valori aleatorii dintr-un interval specific" << endl;
	Sort functie1(5, 6, 16);
	cout << "Vector: ";
	functie1.Print();
	cout << endl;
	cout << "Numarul de elemente: "<<functie1.GetElementsCount() << endl;
	cout << "Elementul de la indexul 2: "<< functie1.GetElementFromIndex(2) << endl;
	functie1.BubbleSort(false);
	cout << "Vectorul sortat: ";
	functie1.Print();
	cout << endl;

	cout << endl<< "Exemplul 2, lista cu valori dintr-un vector existent" << endl;
	int v[5] = { 4, 9, 5, 1, 2 };
	Sort functie2(v, 5);
	cout << "Vector: ";
	functie2.Print();
	cout << endl;
	cout << "Numarul de elemente: " << functie2.GetElementsCount() << endl;
	cout << "Elementul de la indexul 4: " << functie2.GetElementFromIndex(4) << endl;
	functie2.InsertSort(false);
	cout << "Vector sortat: "; 
	functie2.Print();
	cout << endl;

	cout <<endl<< "Exemplul 3, lista cu parametrii varidici" << endl;
	Sort functie3(5, 3, 5, 2, 56, 1);
	cout << "Vector: ";
	functie3.Print();
	cout << endl;
	cout << "Numarul de elemente: " << functie3.GetElementsCount() << endl;
	cout << "Elementul de la indexul 3: " << functie3.GetElementFromIndex(3) << endl;
	functie3.QuickSort(false);
	cout << "Vector sortat: ";
	functie3.Print();
	cout << endl;

	cout <<endl<< "Exemplul 4, lista cu valori dintr-un sir de caractere" << endl;
	char s[100] = {"6,8,3,4,9"};
	Sort functie4(s);
	cout << "Vector: ";
	functie4.Print();
	cout << endl;
	cout << "Numarul de elemente: " << functie4.GetElementsCount() << endl;
	cout << "Elementul de la indexul 2: " << functie4.GetElementFromIndex(2) << endl;
	functie4.BubbleSort(false);
	cout << "Vector sortat: ";
	functie4.Print();
	cout << endl;

	cout <<endl<< "Exemplul 5, lista cu valori dintr-o lista de initializare" << endl;
	Sort functie5({ 5, 70, 25, 33, 14 });
	cout << "Vector: ";
	functie5.Print();
	cout << endl;
	cout << "Numarul de elemente: " << functie5.GetElementsCount() << endl;
	cout << "Elementul de la indexul 2: " << functie5.GetElementFromIndex(2) << endl;
	functie5.BubbleSort(false);
	cout << "Vector sortat: ";
	functie5.Print();
	cout << endl;
	return 0;
}