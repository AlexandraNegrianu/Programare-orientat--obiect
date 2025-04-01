#pragma once

#include "Car.h"
class Seat :public Car {
public:
	Seat();
	char* GetName();
	int RaceTime(int lungime, Weather vreme);
};
