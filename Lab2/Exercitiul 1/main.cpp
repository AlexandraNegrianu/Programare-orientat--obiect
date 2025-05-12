#include <iostream>
#include "NumberList.h"

using namespace std;
int v[10], n;
int main()
{
	NumberList l1;

	cin >> n;
	l1.Init();
	for (int i = 0; i < n; i++) 
	{
		cin >> v[i];
		l1.Add(v[i]);
	}


	l1.Sort();
	l1.Print();
}
