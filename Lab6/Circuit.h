#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit {
protected:
	int lungime;
	Car* masina[100];
	Weather vreme;
	int nr_masini = 0;
	int timp[100];

public:
	void SetLength(int lungime);
	void SetWeather(Weather vreme);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};
