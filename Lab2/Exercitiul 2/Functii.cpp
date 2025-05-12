#include <iostream>
#include <cstring>

#include "Functii.h"

using namespace std;

int cmp_nume(Student p1, Student p2)
{
	if (strcmp(p1.Dai_Nume(), p2.Dai_Nume()) > 0)
		return 1;
	if (strcmp(p1.Dai_Nume(), p2.Dai_Nume()) < 0)
		return -1;
	return 0;
}

int cmp_mate(Student p1, Student p2)
{
	if (p1.Dai_Mate() < p2.Dai_Mate())
		return -1;
	if (p1.Dai_Mate() > p2.Dai_Mate())
		return 1;
	return 0;
}
int cmp_eng(Student p1, Student p2)
{
	if (p1.Dai_Eng() < p2.Dai_Eng())
		return -1;
	if (p1.Dai_Eng() > p2.Dai_Eng())
		return 1;
	return 0;
}
int cmp_ist(Student p1, Student p2)
{
	if (p1.Dai_Ist() < p2.Dai_Ist())
		return -1;
	if (p1.Dai_Ist() > p2.Dai_Ist())
		return 1;
	return 0;
}
int cmp_medie(Student p1, Student p2)
{
	if (p1.Dai_Medie() < p2.Dai_Medie())
		return -1;
	if (p1.Dai_Medie() > p2.Dai_Medie())
		return 1;
	return 0;
}
int cmptot(int maxi1, int maxi2, Student p1, Student p2)
{
	if (cmp_nume(p1, p2) > 0)
		maxi1++;
	else if (cmp_nume(p1, p2) < 0)
		maxi2++;

	if (cmp_mate(p1, p2) > 0)
		maxi1++;
	else if (cmp_mate(p1, p2) < 0)
		maxi2++;

	if (cmp_eng(p1, p2) > 0)
		maxi1++;
	else if (cmp_eng(p1, p2) < 0)
		maxi2++;

	if (cmp_ist(p1, p2) > 0)
		maxi1++;
	else if (cmp_ist(p1, p2) < 0)
		maxi2++;

	if (cmp_medie(p1, p2) > 0)
		maxi1++;
	else if (cmp_medie(p1, p2) < 0)
		maxi2++;

	if (maxi1 > maxi2)
		return 1;
	if (maxi2 > maxi1)
		return -1;
	return 0;

}
