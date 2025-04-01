#pragma once

#include "Car.h"
class BMW :public Car {
public:
	BMW();
	char* GetName();
	int RaceTime(int lungime, Weather vreme);
};
