#include <iostream>
#include <cstring>
#include "Student.h"

#include "Functii.h"

using namespace std;


int main()
{
	Student p1, p2;

	char nume1[256], nume2[256];
	cin.getline(nume1, 256);
	cin.getline(nume2, 256);

	p1.Ia_Nume(nume1);
	p2.Ia_Nume(nume2);

	float mate1, mate2, eng1, eng2, ist1, ist2;

	cin >> mate1 >> mate2>>eng1>>eng2>>ist1>>ist2;

	float medie1 = p1.Dai_Medie();
	float medie2 = p2.Dai_Medie();

	p1.Ia_Mate(mate1);
	p2.Ia_Mate(mate2);

	p1.Ia_Eng(eng1);
	p2.Ia_Eng(eng2);

	p1.Ia_Ist(ist1);
	p2.Ia_Ist(ist2);

	int maxi1 = 0, maxi2 = 0;
	cout<<cmptot(maxi1, maxi2, p1, p2);
	

}
