#pragma once
#include "Weather.h"
class Car {

protected:
	int rezervor, consum, viteza_medie[3];
	// viteza_medie[] -> pentru fiecare tip de vreme dintre cele trei declarate

	char nume_masina[20];
public:

	virtual char* GetName() = 0;
	virtual int RaceTime(int lungime, Weather vreme) = 0;

};