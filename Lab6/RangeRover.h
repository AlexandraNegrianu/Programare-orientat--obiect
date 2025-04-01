#pragma once

#include "Car.h"
class RangeRover :public Car {
public:
	RangeRover();
	char *GetName();
	int RaceTime(int lungime, Weather vreme);
};
