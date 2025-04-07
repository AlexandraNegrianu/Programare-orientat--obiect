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
    
    int timpi_sortati[100];
    Car* masini_sortate[100];
    int n = 0; // Numărul mașinilor care au terminat cursa 

   
    for (int i = 0; i < nr_masini; i++) {
        if (timp[i] != -1) { 
            timpi_sortati[n] = timp[i];
            masini_sortate[n] = masina[i];
            n++;
        }
    }

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (timpi_sortati[i] < timpi_sortati[j]) {
                
                int aux = timpi_sortati[i];
                timpi_sortati[i] = timpi_sortati[j];
                timpi_sortati[j] = aux;

                Car* aux_masina = masini_sortate[i];
                masini_sortate[i] = masini_sortate[j];
                masini_sortate[j] = aux_masina;
            }
        }
    }

    for (int i = 0; i < n; i++) 
        cout << masini_sortate[i]->GetName() << " a terminat cursa in " << timpi_sortati[i] << " minute" << endl;
    
}


void Circuit::ShowWhoDidNotFinish() {

	for (int i = 0; i < nr_masini; i++) 
		if (timp[i] == -1) // Mașina care nu a terminat cursa
			cout << masina[i]->GetName() << " nu a reusit sa termine cursa" << endl;
		
	
}
