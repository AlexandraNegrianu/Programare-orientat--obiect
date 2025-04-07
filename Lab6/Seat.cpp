#include <iostream>
#include <cstring>
#include "Weather.h"
#include "Seat.h"

using namespace std;

Seat::Seat(){
	
		rezervor = 65;
		consum = 7;
		viteza_medie[Rain] = 50;
		viteza_medie[Sunny] = 60;
		viteza_medie[Snow] = 45;
		strcpy(nume_masina, "Seat");
}

char* Seat::GetName() {
	return nume_masina;
}

int Seat::RaceTime(int lungime, Weather vreme) {
	int dist = rezervor / consum * 100; // Distanța pe care o poate parcurge mașina
	if (dist < lungime) // Dacă distanța este mai mică decât lungimea circuitului mașina nu poate termina cursa
		return -1;
	else return (lungime * 60) / viteza_medie[vreme]; // În caz contrar se calculează timpul necesar
}
