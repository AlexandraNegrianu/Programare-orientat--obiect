#pragma once

#include "Car.h"
class Fiat :public Car {
public:
	Fiat();
	char* GetName();
	int RaceTime(int lungime, Weather vreme);
};
