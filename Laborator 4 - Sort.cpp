#include <iostream>
#include "Sort.h"
#include <initializer_list> // Pentru constructorul cu lista de inițializare
#include <vector> 
#include <cstdarg> 
using namespace std;

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < nrElemente; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j > 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	ascendent = true;
}

int partitioneaza(int arr[], int p, int q) {
	int x = arr[p];
	int i = p + 1;
	int j = 1;
	while (i <= j) {
		if (arr[i] <= x) i++;
		else if (arr[j] >= x) j--;
		else if (i<j && arr[i]>x && arr[j] < x) {
			swap(arr[i], arr[j]);
		}

		arr[p] = arr[i - 1];
		arr[i - 1] = x;
		return i - 1;
	}
}

void QuickSort_recursiv(int arr[], int p, int q)
{
	if(p<q) {
		int m = partitioneaza(arr, p, q);
		QuickSort_recursiv(arr, p, m - 1);
		QuickSort_recursiv(arr, m + 1, q);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSort_recursiv(arr, 0, nrElemente - 1);
	ascendent = true;
}


void Sort::BubbleSort(bool ascendent)
{

	for (int i = 0; i < nrElemente - 1; i++) {
		for (int j = i; j < nrElemente; j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
	ascendent = true;
}

void Sort::Print()
{
	for (int i = 0; i < nrElemente;i++)
		cout << arr[i] << " ";
}

int Sort::GetElementsCount()
{
	return nrElemente;
}

int Sort::GetElementFromIndex(int index)
{
	return arr[index];
}

Sort::Sort(int n, int mini, int maxi)
{
	int interval = maxi - mini;
	nrElemente = n;
	for (int i = 0; i < nrElemente; i++)
		arr[i] = rand() % interval + mini; // %interval + mini -> [mini, maxi] 
}


Sort::Sort(initializer_list <int> valoare) {
	int i = 0;
	
	for(int val:valoare)  // Parcurge fiecare element val din valoare 
		arr[i++] = val; // Adăugăm elementul în vector
	nrElemente = i;
}

Sort::Sort(int vector[], int n)
{
	nrElemente = n;
	for (int i = 0; i < n; i++)
		arr[i] = vector[i];
}

Sort::Sort(int n, ...) {
	nrElemente = n;
	va_list argument; //	Declarație variabilă de tip va_list
	va_start(argument, n); // Inițializare lista de argumente
	for (int i = 0; i < n; i++)
		arr[i]=va_arg(argument, int); // Extrage elementul de tip întreg

	va_end(argument); // Curăță lista de argumente
}

Sort::Sort(const char s[100]) {
	nrElemente = 0;
	int i = 0;
	int numarCurent = 0;
	while (s[i] != NULL) {
		if(s[i] != ',')	numarCurent = numarCurent * 10 + s[i] - '0'; // Creează numărul curent
		else {
			arr[nrElemente] = numarCurent; // Adaugă numărul curent în vector
			nrElemente++; 
			numarCurent = 0; // Resetez numărul curent
		}
		i++;
	}
	arr[nrElemente] = numarCurent; // Adaugă ultimul număr
	nrElemente++; 
}

