#include <iostream>
#include <cstring>
#include "Weather.h"
#include "RangeRover.h"

using namespace std;

RangeRover::RangeRover() {

	rezervor = 70;
	consum = 7;
	viteza_medie[Rain] = 70;
	viteza_medie[Sunny] = 55;
	viteza_medie[Snow] = 40;
	strcpy(nume_masina, "RangeRover");
}

char* RangeRover::GetName() {
	return nume_masina;
}

int RangeRover::RaceTime(int lungime, Weather vreme) {
	int dist = rezervor / consum * 100; // Distanța pe care o poate parcurge mașina
	if (dist < lungime) // Dacă distanța este mai mică decât lungimea circuitului mașina nu poate termina cursa
		return -1;
	else return lungime / viteza_medie[vreme]; // În caz contrar se calculează timpul necesar
}
