#pragma once

#include "Car.h"
class Volvo :public Car {
public:
	Volvo();
	char* GetName();
	int RaceTime(int lungime, Weather vreme);
};
