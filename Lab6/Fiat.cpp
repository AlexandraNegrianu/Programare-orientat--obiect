#include <iostream>
#include <cstring>
#include "Weather.h"
#include "Fiat.h"

using namespace std;

Fiat::Fiat() {

	rezervor = 50;
	consum = 5;
	viteza_medie[Rain] = 50;
	viteza_medie[Sunny] = 60;
	viteza_medie[Snow] = 40;
	strcpy(nume_masina, "Fiat");
}

char* Fiat::GetName() {
	return nume_masina;
}

int Fiat::RaceTime(int lungime, Weather vreme) {
	int dist = rezervor / consum * 100; // Distanța pe care o poate parcurge mașina
	if (dist < lungime) // Dacă distanța este mai mică decât lungimea circuitului mașina nu poate termina cursa
		return -1;
	else return lungime / viteza_medie[vreme]; // În caz contrar se calculează timpul necesar
}
