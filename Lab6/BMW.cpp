#include <iostream>
#include <cstring>
#include "Weather.h"
#include "BMW.h"

using namespace std;

BMW::BMW() {

	rezervor = 100;
	consum = 8;
	viteza_medie[Rain] = 70;
	viteza_medie[Sunny] = 65;
	viteza_medie[Snow] = 50;
	strcpy(nume_masina, "BMW");
}

char* BMW::GetName() {
	return nume_masina;
}

int BMW::RaceTime(int lungime, Weather vreme) {
	int dist = rezervor / consum * 100; // Distanța pe care o poate parcurge mașina
	if (dist < lungime) // Dacă distanța este mai mică decât lungimea circuitului mașina nu poate termina cursa
		return -1;
	else return (lungime * 60) / viteza_medie[vreme]; // În caz contrar se calculează timpul necesar
}
