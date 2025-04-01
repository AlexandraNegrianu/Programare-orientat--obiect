#include <iostream>
#include <cstring>
#include "Circuit.h"
using namespace std;

void Circuit::SetLength(int lungime) {
	this->lungime = lungime;
}

void Circuit::SetWeather(Weather vreme) {
	this->vreme = vreme;
}

void Circuit::AddCar(Car* c) {
	masina[nr_masini] = c;
	nr_masini++;
}

void Circuit::Race() {
	for (int i = 0;i < nr_masini;i++)
		timp[i] = masina[i]->RaceTime(lungime, vreme);
}

void Circuit::ShowFinalRanks() {
	for (int i = 0; i < nr_masini;i++)
		if (timp[i])
			cout << masina[i]->GetName() << " " << timp[i] << endl;
}

void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < nr_masini;i++)
		if (!timp[i])
			cout << masina[i]->GetName() << " " << timp[i] << endl;
}