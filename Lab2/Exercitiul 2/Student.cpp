#include <iostream>
#include "Student.h"
#include <cstring>
using namespace std;

void Student::Ia_Nume(char s[256])
{
	strcpy_s(nume, s);
}
char* Student::Dai_Nume()
{
	return nume;
}


void Student::Ia_Mate(float nota)
{
	mate = nota;
}
float Student::Dai_Mate()
{
	return mate;
}


void Student::Ia_Eng(float nota)
{
	eng = nota;
}
float Student::Dai_Eng()
{
	return eng;
}


void Student::Ia_Ist(float nota)
{
	ist = nota;
}
float Student::Dai_Ist()
{
	return ist;
}


float Student::Dai_Medie()
{
	return (mate + eng + ist) / 3;
}
